#include "../include/request.hpp"

namespace http {
    Request::Request() {}

    Request::Request(const std::string &request) {
        std::string start_line, header, body;
        std::string method, line, key, value;
        std::istringstream stream;
        size_t left = 0, right = 0;

        // Parse start_line
        right = request.find("\r\n", left);
        start_line = request.substr(left, right - left);
        stream.str(start_line);
        stream >> method >> _path >> _version;
        _method = http::to_method(method);

        // Parse query parameters
        stream.clear();
        stream.str(_path);
        std::getline(stream, line, '?');
        while (std::getline(stream, line, '&')) {
            std::istringstream query_stream(line);
            std::getline(query_stream, key, '=');
            std::getline(query_stream, value);
            _query[key] = value;
        }

        // Parse header and body
        left = right + 2;
        right = request.find("\r\n\r\n", left);
        if (right != std::string::npos) {
            header = request.substr(left, right - left);
            left = right + 4;
            right = request.length();
            if (left < right) { _body = request.substr(left, right - left); }
        }
        stream.clear();
        stream.str(header);
        while (std::getline(stream, line)) {
            std::istringstream header_stream(line);
            std::getline(header_stream, key, ':');
            std::getline(header_stream, value);
            // Remove whitespaces
            key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
            value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
            _headers[key] = value;
        }
    }

    void Request::set_method(const Method &method) { _method = method; }

    std::string Request::get_query(const std::string &key) { return _query[key]; }

    Method Request::method() { return _method; }

    std::string Request::path() { return _path; }

    std::unordered_map<std::string, std::string> Request::query() {
        return _query;
    }
}
