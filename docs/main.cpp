#include <fstream>
#include <sstream>

#include "../include/server.hpp"

void home(http::Request &req, http::Response &res) {
    std::ifstream file;
    std::ostringstream stream;
    switch (req.method()) {
    case http::Method::GET:
        file.open("./docs/index.html");
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

void not_found(http::Request &req, http::Response &res) {
    std::ifstream file;
    std::ostringstream stream;
    file.open("./docs/notFound.html");
    stream << file.rdbuf();
    res.set_status_code(http::Status::NOT_FOUND);
    res.set_content_type(http::MIME::HTML);
    res.set_body(stream.str());
}

int main() {
    http::Server server(8080);
    server.handle_static_files("./docs/static");

    server.handle(R"(^(\/)home(\/)?$)", home);
    server.handle(R"(^(\/)(.*)$)", not_found);
    server.listen_and_serve();
    return 0;
}
