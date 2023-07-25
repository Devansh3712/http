#include "../include/server.hpp"

void root(http::Request &req, http::Response &res) {
    http::Method method = req.method();
    switch (method) {
    case http::Method::GET:
        res.set_status_code(http::Status::OK);
        res.set_header("Content-Type", "text/plain");
        res.set_body("hello, world!");
        return;
    default:
        res.set_status_code(http::Status::METHOD_NOT_ALLOWED);
        return;
    }
}

void test(http::Request &req, http::Response &res) {
    res.set_status_code(http::Status::OK);
    res.set_header("Content-Type", "text/plain");
    res.set_body(req.body());
}

int main() {
    http::Server s(8080);
    s.handle("/test", test);
    s.handle("/", root);
    s.listen_and_serve();
    return 0;
}
