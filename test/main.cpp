#include <chrono>

#include "../include/request.hpp"
#include "../include/response.hpp"

size_t passed = 0, failed = 0;

void test_pass(const std::string &test) {
    ++passed;
    std::cout << "[+] " << test << " PASSED" << std::endl;
}

void test_fail(const std::string &test, const std::string &expected, std::string found) {
    ++failed;
    std::cerr << "[-] " << test << " FAILED" << std::endl;
    std::cerr << "[?] Expected: " << expected << " Got: " << found << std::endl;
    std::cout << std::endl;
}

void test_request() {
    std::ostringstream request;
    http::Request req;

    req.set_method(http::Method::GET);
    if (http::to_string(req.method()) != "GET") {
        test_fail("test_request_set_method", "GET", http::to_string(req.method()));
    } else { test_pass("test_request_set_method"); }

    req.set_path("/");
    if (req.path() != "/") {
        test_fail("test_request_set_path", "/", req.path());
    } else { test_pass("test_request_set_path"); }

    req.set_version(DEFAULT_HTTP_VERSION);
    if(req.version() != "HTTP/1.1") {
        test_fail("test_request_set_version", "HTTP/1.1", req.version());
    } else { test_pass("test_request_set_version"); }

    req.set_content_type(http::MIME::TXT);
    if (http::to_string(req.content_type()) != "text/plain") {
        test_fail("test_request_set_content_type", "text/plain", http::to_string(req.content_type()));
    } else { test_pass("test_request_set_content_type"); }

    request << "GET / HTTP/1.1" << CRLF;
    request << "Content-Type: text/plain" << CRLF;
    request << CRLF;
    if (request.str() != req.to_string()) {
        test_fail("test_request_to_string", request.str(), req.to_string());
    } else { test_pass("test_request_to_string"); }
}

void test_response() {
    std::ostringstream response;
    http::Response res;
    std::string json_body = R"({"message":"hello world"})";

    res.set_status_code(http::Status::OK);
    if (http::to_string(res.status_code()) != "OK") {
        test_fail("test_response_set_status_code", "OK", http::to_string(res.status_code()));
    } else { test_pass("test_response_set_status_code"); }

    res.set_content_type(http::MIME::JSON);
    if (http::to_string(res.content_type()) != "application/json") {
        test_fail("test_response_set_content_type", "application/json", http::to_string(res.content_type()));
    } else { test_pass("test_response_set_content_type"); }

    res.set_body(json_body);

    response << "HTTP/1.1 200 OK" << CRLF;
    response << "Content-Type: application/json" << CRLF;
    response << CRLF;
    response << json_body;
    if (response.str() != res.to_string()) {
        test_fail("test_response_to_string", response.str(), res.to_string());
    } else { test_pass("test_response_to_string"); }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    test_request();
    test_response();
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time = stop - start;
    std::cout << std::endl;
    std::cout << "Tests passed: " << passed << std::endl;
    std::cout << "Tests failed: " << failed << std::endl;
    std::cout << "Execution time: " << time.count() << " ms" << std::endl; 
    return 0;
}
