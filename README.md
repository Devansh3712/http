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
        res.set_content_type(http::MIME::TXT);
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

### To Do

- [x] Create Enum class for common MIME types
- [x] Add cookie methods to `Message` class
- [x] Parse cookie in `Request` constructor
- [x] Overload `<<` operator for `Request` and `Response`
- [x] Dockerize a sample server
- [ ] Create a JSON parser

References:

- https://github.com/trungams/http-server
- https://bruinsslot.jp/post/simple-http-webserver-in-c/
