#include "../include/mimes.hpp"

namespace http {
    std::string to_string(const MIME &mime) {
        switch(mime) {
        case MIME::AAC: return "audio/aac";
        case MIME::ABW: return "application/x-abiword";
        case MIME::ARC: return "application/x-freearc";
        case MIME::AVIF: return "image/avif";
        case MIME::AVI: return "video/x-msvideo";
        case MIME::AZW: return "application/vnd.amazon.ebook";
        case MIME::BIN: return "application/octet-stream";
        case MIME::BMP: return "image/bmp";
        case MIME::BZ: return "application/x-bzip";
        case MIME::BZ2: return "application/x-bzip2";
        case MIME::CDA: return "application/x-cdf";
        case MIME::CSH: return "application/x-csh";
        case MIME::CSS: return "text/css";
        case MIME::CSV: return "text/csv";
        case MIME::DOC: return "application/msword";
        case MIME::DOCX: return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
        case MIME::EOT: return "application/vnd.ms-fontobject";
        case MIME::EPUB: return "application/epub+zip";
        case MIME::GZ: return "application/gzip";
        case MIME::GIF: return "image/gif";
        case MIME::HTM: return "text/html";
        case MIME::HTML: return "text/html";
        case MIME::ICO: return "image/vnd.microsoft.icon";
        case MIME::ICS: return "text/calendar";
        case MIME::JAR: return "application/java-archive";
        case MIME::JPEG: return "image/jpeg";
        case MIME::JPG: return "image/jpeg";
        case MIME::JS: return "text/javascript";
        case MIME::JSON: return "application/json";
        case MIME::JSONLD: return "application/ld+json";
        case MIME::MID: return "audio/midi";
        case MIME::MIDI: return "audio/midi";
        case MIME::MJS: return "text/javascript";
        case MIME::MP3: return "audio/mpeg";
        case MIME::MP4: return "video/mp4";
        case MIME::MPEG: return "video/mpeg";
        case MIME::MPKG: return "application/vnd.apple.installer+xml";
        case MIME::ODP: return "application/vnd.oasis.opendocument.presentation";
        case MIME::ODS: return "application/vnd.oasis.opendocument.spreadsheet";
        case MIME::ODT: return "application/vnd.oasis.opendocument.text";
        case MIME::OGA: return "audio/ogg";
        case MIME::OGV: return "video/ogg";
        case MIME::OGX: return "application/ogg";
        case MIME::OPUS: return "audio/opus";
        case MIME::OTF: return "font/otf";
        case MIME::PNG: return "image/png";
        case MIME::PDF: return "application/pdf";
        case MIME::PHP: return "application/x-httpd-php";
        case MIME::PPT: return "application/vnd.ms-powerpoint";
        case MIME::PPTX: return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
        case MIME::RAR: return "application/vnd.rar";
        case MIME::RTF: return "application/rtf";
        case MIME::SH: return "application/x-sh";
        case MIME::SVG: return "image/svg+xml";
        case MIME::TAR: return "application/x-tar";
        case MIME::TIF: return "image/tiff";
        case MIME::TIFF: return "image/tiff";
        case MIME::TS: return "	video/mp2t";
        case MIME::TTF: return "font/ttf";
        case MIME::TXT: return "text/plain";
        case MIME::VSD: return "application/vnd.visio";
        case MIME::WAV: return "audio/wav";
        case MIME::WEBA: return "audio/webm";
        case MIME::WEBM: return "video/webm";
        case MIME::WEBP: return "image/webp";
        case MIME::WOFF: return "font/woff";
        case MIME::WOFF2: return "font/woff2";
        case MIME::XHTML: return "application/xhtml+xml";
        case MIME::XLS: return "application/vnd.ms-excel";
        case MIME::XLSX: return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
        case MIME::XML: return "application/xml";
        case MIME::XUL: return "application/vnd.mozilla.xul+xml";
        case MIME::ZIP: return "application/zip";
        case MIME::_7Z: return "application/x-7z-compressed";
        default: throw std::invalid_argument("Not a valid MIME type");
        }
    }

    MIME to_mime_type(const std::string &string) {
        if (string == "audio/aac") { return MIME::AAC; }
        else if (string == "application/x-abiword") { return MIME::ABW; }
        else if (string == "application/x-freearc") { return MIME::ARC; }
        else if (string == "image/avif") { return MIME::AVIF; }
        else if (string == "video/x-msvideo") { return MIME::AVI; }
        else if (string == "application/vnd.amazon.ebook") { return MIME::AZW; }
        else if (string == "application/octet-stream") { return MIME::BIN; }
        else if (string == "image/bmp") { return MIME::BMP; }
        else if (string == "application/x-bzip") { return MIME::BZ; }
        else if (string == "application/x-bzip2") { return MIME::BZ2; }
        else if (string == "application/x-cdf") { return MIME::CDA; }
        else if (string == "application/s-csh") { return MIME::CSH; }
        else if (string == "text/css") { return MIME::CSS; }
        else if (string == "text/csv") { return MIME::CSV; }
        else if (string == "application/msword") { return MIME::DOC; }
        else if (string == "application/vnd.openxmlformats-officedocument.wordprocessingml.document") { return MIME::DOCX; }
        else if (string == "application/vnd.ms-fontobject") { return MIME::EOT; }
        else if (string == "application/epub+zip") { return MIME::EPUB; }
        else if (string == "application/gzip") { return MIME::GZ; }
        else if (string == "image/gif") { return MIME::GIF; }
        else if (string == "text/html") { return MIME::HTML; }
        else if (string == "image/vnd.microsoft.icon") { return MIME::ICO; }
        else if (string == "text/calendar") { return MIME::ICS; }
        else if (string == "application/java-archive") { return MIME::JAR; }
        else if (string == "image/jpeg") { return MIME::JPEG; }
        else if (string == "text/javascript") { return MIME::JS; }
        else if (string == "application/json") { return MIME::JSON; }
        else if (string == "application/ld+json") { return MIME::JSONLD; }
        else if (string == "audio/midi") { return MIME::MIDI; }
        else if (string == "audio/mpeg") { return MIME::MP3; }
        else if (string == "video/mp4") { return MIME::MP4; }
        else if (string == "video/mpeg") { return MIME::MPEG; }
        else if (string == "application/vnd.apple.installer+xml") { return MIME::MPKG; }
        else if (string == "application/vnd.oasis.opendocument.presentation") { return MIME::ODP; }
        else if (string == "application/vnd.oasis.opendocument.spreadsheet") { return MIME::ODS; }
        else if (string == "application/vnd.oasis.opendocument.text") { return MIME::ODT; }
        else if (string == "audio/ogg") { return MIME::OGA; }
        else if (string == "video/ogg") { return MIME::OGV; }
        else if (string == "application/ogg") { return MIME::OGX; }
        else if (string == "audio/opus") { return MIME::OPUS; }
        else if (string == "font/otf") { return MIME::OTF; }
        else if (string == "image/png") { return MIME::PNG; }
        else if (string == "application/pdf") { return MIME::PDF; }
        else if (string == "application/x-httpd-php") { return MIME::PHP; }
        else if (string == "application/vnd.ms-powerpoint") { return MIME::PPT; }
        else if (string == "application/vnd.openxmlformats-officedocument.presentationml.presentation") { return MIME::PPTX; }
        else if (string == "application/vnd.rar") { return MIME::RAR; }
        else if (string == "application/rtf") { return MIME::RTF; }
        else if (string == "application/x-sh") { return MIME::SH; }
        else if (string == "image/svg+xml") { return MIME::SVG; }
        else if (string == "application/x-tar") { return MIME::TAR; }
        else if (string == "image/tiff") { return MIME::TIFF; }
        else if (string == "video/mp2t") { return MIME::TS; }
        else if (string == "font/ttf") { return MIME::TTF; }
        else if (string == "text/plain") { return MIME::TXT; }
        else if (string == "application/vnd.visio") { return MIME::VSD; }
        else if (string == "audio/wav") { return MIME::WAV; }
        else if (string == "audio/webm") { return MIME::WEBA; }
        else if (string == "video/webm") { return MIME::WEBM; }
        else if (string == "image/webp") { return MIME::WEBP; }
        else if (string == "font/woff") { return MIME::WOFF; }
        else if (string == "font/woff2") { return MIME::WOFF2; }
        else if (string == "application/xhtml+xml") { return MIME::XHTML; }
        else if (string == "application/vnd.ms-excel") { return MIME::XLS; }
        else if (string == "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet") { return MIME::XLSX; }
        else if (string == "application/xml") { return MIME::XML; }
        else if (string == "application/vnd.mozilla.xul+xml") { return MIME::XUL; }
        else if (string == "application/zip") { return MIME::ZIP; }
        else if (string == "application/x-7z-compressed") { return MIME::_7Z; }
        else { throw std::invalid_argument("Not a valid MIME type"); }
    }
}
