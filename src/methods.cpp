#include "../include/methods.hpp"

namespace http {
    std::string to_string(const Method &method) {
        switch (method) {
        // The GET method requests a representation of the specified resource.
        // Requests using GET should only retrieve data.
        case Method::GET: return "GET";
        // The HEAD method asks for a response identical to a GET request,
        // but without the response body.
        case Method::HEAD: return "HEAD";
        // The POST method submits an entity to the specified resource,
        // often causing a change in state or side effects on the server.
        case Method::POST: return "POST";
        // The PUT method replaces all current representations of the target
        // resource with the request payload.
        case Method::PUT: return "PUT";
        // The DELETE method deletes the specified resource.
        case Method::DELETE: return "DELETE";
        // The CONNECT method establishes a tunnel to the server identified
        // by the target resource.
        case Method::CONNECT: return "CONNECT";
        // The OPTIONS method describes the communication options for the
        // target resource.
        case Method::OPTIONS: return "OPTIONS";
        // The TRACE method performs a message loop-back test along the path
        // to the target resource.
        case Method::TRACE: return "TRACE";
        // The PATCH method applies partial modifications to a resource.
        case Method::PATCH: return "PATCH";
        default: throw std::invalid_argument("Not a valid HTTP method");
        }
    }

    Method to_method(const std::string &string) {
        if (string == "GET") { return Method::GET; }
        else if (string == "HEAD") { return Method::HEAD; }
        else if (string == "POST") { return Method::POST; }
        else if (string == "PUT") { return Method::PUT; }
        else if (string == "DELETE") { return Method::DELETE; }
        else if (string == "CONNECT") { return Method::CONNECT; }
        else if (string == "OPTIONS") { return Method::OPTIONS; }
        else if (string == "TRACE") { return Method::TRACE; }
        else if (string == "PATCH") { return Method::PATCH; }
        throw std::invalid_argument("Not a valid HTTP method");
    }
}
