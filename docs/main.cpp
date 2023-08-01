#include "../include/server.hpp"

void page(http::Request &req, http::Response &res, const std::string &file_name) {
    std::ifstream file;
    std::ostringstream stream;
    switch (req.method()) {
    case http::Method::GET:
        file.open("./docs/" + file_name);
        stream << file.rdbuf();
        res.set_status_code(http::Status::OK);
        res.set_content_type(http::MIME::HTML);
        res.set_body(stream.str());
        file.close();
        return;
    default:
        res.set_status_code(http::Status::METHOD_NOT_ALLOWED);
    }
}

void home(http::Request &req, http::Response &res) { page(req, res, "index.html"); }

void methods(http::Request &req, http::Response &res) { page(req, res, "methods.html"); }

void not_found(http::Request &req, http::Response &res) {
    std::ifstream file;
    std::ostringstream stream;
    file.open("./docs/404.html");
    stream << file.rdbuf();
    res.set_status_code(http::Status::NOT_FOUND);
    res.set_content_type(http::MIME::HTML);
    res.set_body(stream.str());
}

int main() {
    http::Server server(8080);
    server.handle_static_files("./docs/static");

    server.handle(R"(^(\/)home(\/)?$)", home);
    server.handle(R"(^(\/)methods(\/)?$)", methods);
    server.handle(R"(^(\/)(.*)$)", not_found);
    server.listen_and_serve();
    return 0;
}
