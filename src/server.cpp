#include "../include/server.hpp"

namespace http {
    Server::Server(unsigned int port) {
        // socket(int domain, int type, int protocol) creates an endpoint
        // for communication and returns a file descriptor that refers to
        // that endpoint.
        // 
        // domain specifies a communication domain, selects a protocol
        // family which will be used for communication.
        // AF_INET provides IPv4 Internet protocols.
        //
        // type specifies the communication semantics.
        // SOCK_STREAM provides sequenced, reliable, two-way, connection-based
        // byte streams, used to open a TCP socket.
        //
        // protocol specifies a particular protocol to be used with the socket.
        // Normally only a single protocol exists to support a particular
        // socket type within a given protocol family, in which case it can be
        // specified as 0.
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        // setsockopt() manipulates options for the socket referred to by
        // the file descriptor sockfd. To manipulate options at the sockets
        // API level, level is specified as SOL_SOCKET.
        const int opt = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        // An IP socket address is defined as a combination of an IP interface
        // address and a 16-bit port number.
        //
        // sin_family is always set to AF_INET.
        addr.sin_family = AF_INET;
        // sin_port contains the port in Network Byte Order.
        // 
        // To allow machines with different byte order conventions communicate
        // with each other, the Internet protocols specify a canonical byte
        // order convention for data transmitted over the network. This is
        // known as Network Byte Order.
        addr.sin_port = htons(port);
        // sin_addr is the IP host address. s_addr contains the host interface
        // address in network byte order.
        // INADDR_ANY (0.0.0.0) means any address for binding.
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr_len = sizeof(addr);

        // bind() assigns the address specified by addr to the socket referred
        // to by the file descriptor sockfd, also called as "assigning a name
        // to a socket".
        //
        // It is normally necessary to assign a local address using bind()
        // before a SOCK_STREAM socket may receive connections.
        if (bind(sockfd, (sockaddr *)&addr, addr_len) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }
    }

    Server::~Server() {
        close(sockfd);
    }

    void Server::listen_and_serve() {
        // listen(int sockfd, int backlog) marks the socket referred to by
        // sockfd as a passive socket, that will be used to accept incoming
        // connection requests using accept().
        //
        // backlog defines the maximum length to which the queue of pending
        // connections for sockfd may grow.
        if (listen(sockfd, SOMAXCONN) == -1) {
            std::string error = std::strerror(errno);
            throw std::runtime_error(error);
        }

        // accept() is used with connection-based socket types. It extracts the
        // first connection request on the queue of pending connections for the
        // listening socket, and returns a new file descriptor referring to
        // that socket. The newly created socket is not in the listening state.
        while (true) {
            int new_sockfd = accept(sockfd, (sockaddr *)&addr, (socklen_t *)&addr_len);
            if (new_sockfd == -1) {
                std::cout << std::strerror(errno);
                continue;
            }

            // Read the incoming request and parse it using Request class.
            int val_read = 0;
            std::string request;
            std::vector<char> buffer(MAX_BUFFER_SIZE);
            do {
                val_read = read(new_sockfd, &buffer[0], buffer.size());
                if (val_read == -1) { break; }
                request.append(buffer.cbegin(), buffer.cend());
            } while (val_read == MAX_BUFFER_SIZE);
            Request _request(request);

            // Match and serve route if present
            auto start = std::chrono::high_resolution_clock::now();
            Response _response(_request);
            handler(_request, _response);
            std::string response = _response.to_string();
            if (write(new_sockfd, response.c_str(), response.size()) == -1) {
                std::cout << std::strerror(errno);
                continue;
            }
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time = stop - start;
            log(_request, _response, time.count());

            close(new_sockfd);
        }
    }

    // Iterate through the routes vector and match the regex.
    // If a match is found, execute the function, else return
    // 404 NOT FOUND.
    void Server::handler(Request &request, Response &response) {
        std::string path = request.path();
        for (auto item: routes) {
            if (std::regex_search(path, item.first)) {
                item.second(request, response);
                return;
            }
        }
        response.set_status_code(Status::NOT_FOUND);
    }

    // Log all incoming requests
    void Server::log(Request &request, Response &response, double time) {
        std::ostringstream stream;
        auto timestamp = std::time(nullptr);
        auto local_timestamp = *std::localtime(&timestamp);

        stream << '[' << std::put_time(&local_timestamp, "%d-%m-%Y %H:%M:%S") << "] ";
        stream << to_code(response.status_code()) << ' ';
        stream << to_string(request.method()) << ' ';
        stream << request.path() << ' ';
        stream << time << " ms";

        std::cout << stream.str() << std::endl;
    }

    // Maintain a vector of { route, func } where route is the regex for
    // an endpoint and the func is the related function.
    void Server::handle(const std::string &route, function func) {
        std::regex route_regex(route);
        routes.push_back(std::make_pair(route_regex, func));
    }
}
