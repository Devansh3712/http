#pragma once

#include <sstream>
#include <unordered_map>

#include "message.hpp"
#include "request.hpp"
#include "status.hpp"

namespace http {
    class Response: public Message {
    private:
        Status _status_code;
    public:
        Response();
        Response(Request &request);
        Response(const std::string &body, std::string version, const Status &status_code = Status::OK);
        void set_status_code(const Status &status_code);
        std::string to_string();
        Status status_code();
    };
}
