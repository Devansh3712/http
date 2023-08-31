#include "../include/tlsserver.hpp"

namespace http {
    TLSServer::TLSServer(unsigned int port, std::string certificate, std::string private_key): http::Server(port) {
        this->port = port;
        this->certificate = certificate;
        this->private_key = private_key;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }
        const int opt = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(this->port);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr_len = sizeof(addr);

        if (bind(sockfd, (sockaddr *)&addr, addr_len) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        const SSL_METHOD *method = TLS_server_method();

        context = SSL_CTX_new(method);
        if (!context) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }
        // Set SSL certificate generated using a CA
        if (SSL_CTX_use_certificate_file(context, certificate.c_str(), SSL_FILETYPE_PEM) <= 0) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }
        // Set the SSL private key
        if (SSL_CTX_use_PrivateKey_file(context, private_key.c_str(), SSL_FILETYPE_PEM) <= 0) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }
    };

    TLSServer::~TLSServer() {
        close(sockfd);
        SSL_CTX_free(context);
    };

    void TLSServer::listen_and_serve() {
        if (listen(sockfd, SOMAXCONN) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        std::ostringstream stream;
        stream << "Listening on: ";
        stream << "https://" << inet_ntoa(addr.sin_addr) << ':' << port;
        stream << std::endl;
        std::cout << stream.str();

        while (true) {
            int new_sockfd = accept(sockfd, (sockaddr *)&addr, (socklen_t *)&addr_len);
            if (new_sockfd == -1) {
                std::cout << std::strerror(errno);
                continue;
            }

            ssl = SSL_new(context);
            SSL_set_fd(ssl, new_sockfd);
            if (SSL_accept(ssl) <= 0) {
                std::cout << std::strerror(errno);
                continue;
            }

            int val_read = 0;
            std::string request;
            std::vector<char> buffer(MAX_BUFFER_SIZE);
            do {
                val_read = SSL_read(ssl, &buffer[0], buffer.size());
                if (val_read == -1) { break; }
                request.append(buffer.cbegin(), buffer.cend());
            } while (val_read == MAX_BUFFER_SIZE);
            Request req(request);

            auto start = std::chrono::high_resolution_clock::now();
            Response res(req);
            router(req, res);
            std::string response = res.to_string();
            if (SSL_write(ssl, response.c_str(), response.size()) == -1) {
                std::cout << std::strerror(errno);
                continue;
            }
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time = stop - start;
            log(req, res, time.count());

            SSL_shutdown(ssl);
            SSL_free(ssl);
            close(new_sockfd);
        }
    }
}
