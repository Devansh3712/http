#pragma once

#include <arpa/inet.h>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <ctime>
#include <experimental/filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <netinet/ip.h>
#include <regex>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>
#include <vector>

#include "../include/request.hpp"
#include "../include/response.hpp"

#define MAX_BUFFER_SIZE 4096

namespace fs = std::experimental::filesystem;

using function = std::function<void(http::Request&, http::Response&)>;

namespace http {
    class Server {
    protected:
        unsigned int port;
        int sockfd;
        int addr_len;
        sockaddr_in addr;
        std::vector<std::pair<std::regex, function>> routes;
        void router(Request &request, Response &response);
        void log(Request &request, Response &response, double time);
    public:
        Server(unsigned int port);
        ~Server();
        void listen_and_serve();
        void handle(const std::string &route, function func);
        void handle_static_files(const std::string &path);
    };
}
