#pragma once

#include <stdexcept>
#include <string>

namespace http {
    enum class Method {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

    std::string to_string(const Method &method);
    Method to_method(const std::string &string);
}
