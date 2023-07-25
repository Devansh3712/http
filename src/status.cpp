#include "../include/status.hpp"

namespace http {
    std::string to_string(const Status &status) {
        switch (status) {
        case Status::CONTINUE: return "CONTINUE";
        case Status::SWITCHING_PROTOCOLS: return "SWITCHING PROTOCOLS";
        case Status::PROCESSING: return "PROCESSING";
        case Status::EARLY_HINTS: return "EARLY HINTS";
        case Status::OK: return "OK";
        case Status::CREATED: return "CREATED";
        case Status::ACCEPTED: return "ACCEPTED";
        case Status::NON_AUTHORITATIVE_INFORMATION: return "NON AUTHORITATIVE INFORMATION";
        case Status::NO_CONTENT: return "NO CONTENT";
        case Status::RESET_CONTENT: return "RESET CONTENT";
        case Status::PARTIAL_CONTENT: return "PARTIAL CONTENT";
        case Status::MULTI_STATUS: return "MULTI STATUS";
        case Status::ALREADY_REPORTED: return "ALREADY REPORTED";
        case Status::IM_USED: return "IM_USED";
        case Status::MULTIPLE_CHOICES: return "MULTIPLE CHOICES";
        case Status::MOVED_PERMANENTLY: return "MOVED PERMANENTLY";
        case Status::FOUND: return "FOUND";
        case Status::SEE_OTHER: return "SEE OTHER";
        case Status::NOT_MODIFIED: return "NOT MODIFIED";
        case Status::USE_PROXY: return "USE PROXY";
        case Status::UNUSED: return "UNUSED";
        case Status::TEMPORARY_REDIRECT: return "TEMPORARY REDIRECT";
        case Status::PERMANENT_REDIRECT: return "PERMANENT REDIRECT";
        case Status::BAD_REQUEST: return "BAD REQUEST";
        case Status::UNAUTHORIZED: return "UNAUTHORIZED";
        case Status::PAYMENT_REQUIRED: return "PAYMENT REQUIRED";
        case Status::FORBIDDEN: return "FORBIDDEN";
        case Status::NOT_FOUND: return "NOT FOUND";
        case Status::METHOD_NOT_ALLOWED: return "METHOD NOT ALLOWED";
        case Status::NOT_ACCEPTABLE: return "NOT ACCEPTABLE";
        case Status::PROXY_AUTHENTICATION_REQUIRED: return "PROXY AUTHENTICATION REQUIRED";
        case Status::REQUEST_TIMEOUT: return "REQUEST TIMEOUT";
        case Status::CONFLICT: return "CONFLICT";
        case Status::GONE: return "GONE";
        case Status::LENGTH_REQUIRED: return "LENGTH REQUIRED";
        case Status::PRECONDITION_FAILED: return "PRECONDITION FAILED";
        case Status::PAYLOAD_TOO_LARGE: return "PAYLOAD TOO LARGE";
        case Status::URI_TOO_LONG: return "URI TOO LONG";
        case Status::UNSUPPORTED_MEDIA_TYPE: return "UNSUPPORTED MEDIA TYPE";
        case Status::RANGE_NOT_SATISFIABLE: return "RANGE NOT SATISFIABLE";
        case Status::EXPECTATION_FAILED: return "EXPECTATION FAILED";
        case Status::IM_A_TEAPOT: return "I'M A TEAPOT";
        case Status::MISDIRECTED_REQUEST: return "MISDIRECTED REQUEST";
        case Status::UNPROCESSABLE_CONTENT: return "UNPROCESSABLE CONTENT";
        case Status::LOCKED: return "LOCKED";
        case Status::FAILED_DEPENDENCY: return "FAILED DEPENDENCY";
        case Status::TOO_EARLY: return "TOO EARLY";
        case Status::UPGRADE_REQUIRED: return "UPGRADE REQUIRED";
        case Status::PRECONDITION_REQUIRED: return "PRECONDITION REQUIRED";
        case Status::TOO_MANY_REQUESTS: return "TOO MANY REQUESTS";
        case Status::REQUEST_HEADER_FIELDS_TOO_LARGE: return "REQUEST HEADER FIELDS TOO LARGE";
        case Status::UNAVAILABLE_FOR_LEGAL_REASONS: return "UNAVAILABLE FOR LEGAL REASONS";
        case Status::INTERNAL_SERVER_ERROR: return "INTERNAL SERVER ERROR";
        case Status::NOT_IMPLEMENTED: return "NOT IMPLEMENTED";
        case Status::BAD_GATEWAY: return "BAD GATEWAY";
        case Status::SERVICE_UNAVAILABLE: return "SERVICE UNAVAILABLE";
        case Status::GATEWAY_TIMEOUT: return "GATEWAY TIMEOUT";
        case Status::HTTP_VERSION_NOT_SUPPORTED: return "HTTP VERSION NOT SUPPORTED";
        case Status::VARIANT_ALSO_NEGOTIATES: return "VARIANT ALSO NEGOTIATES";
        case Status::INSUFFICIENT_STORAGE: return "INSUFFICIENT STORAGE";
        case Status::LOOP_DETECTED: return "LOOP DETECTED";
        case Status::NOT_EXTENDED: return "NOT EXTENDED";
        case Status::NETWORK_AUTHENTICATION_REQUIRED: return "NETWORK AUTHENTICATION REQUIRED";
        default: throw std::invalid_argument("Not a valid HTTP status code");
        }
    }

    int to_code(const Status &status) { return static_cast<int>(status); }
}
