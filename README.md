# HTTP

`http` is a basic web server written in C++ using the linux `sockets` API.

## Usage

Functions for endpoints can be declared using `http::Request&` and `http::Response&` as argument types, with return value `void`.

It can then be handled using the `handle` function, which requires a string route (can be a regular expression) and the respective function declared.

> **Note**
> All classes and functions are under the namespace `http`.

```cpp
#include "../include/server.hpp"

void root(http::Request &req, http::Response &res) {
    http::Method method = req.method();
    switch (method) {
    case http::Method::GET:
        res.set_status(http::Status::OK);
        res.set_header("Content-Type", "text/plain");
        res.set_body("Hello World!");
        return;
    default:
        res.set_status(http::Status::METHOD_NOT_ALLOWED);
        return;
    }
}

int main() {
    http::Server server(8080);
    server.handle("/", root);
    server.listen_and_serve();
    return 0;
}
```

References:

- https://github.com/trungams/http-server
- https://bruinsslot.jp/post/simple-http-webserver-in-c/
