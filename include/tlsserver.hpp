#pragma once

#include <openssl/ssl.h>
#include <openssl/err.h>

#include "server.hpp"

namespace http {
    class TLSServer: public Server {
    private:
        std::string certificate;
        std::string private_key;
        SSL *ssl;
        SSL_CTX *context;
    public:
        TLSServer(unsigned int port, std::string certificate, std::string private_key);
        ~TLSServer();
        void listen_and_serve();
    };
}
