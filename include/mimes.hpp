#pragma once

#include <stdexcept>
#include <string>

namespace http {
    enum class MIME {
        AAC,
        ABW,
        ARC,
        AVIF,
        AVI,
        AZW,
        BIN,
        BMP,
        BZ,
        BZ2,
        CDA,
        CSH,
        CSS,
        CSV,
        DOC,
        DOCX,
        EOT,
        EPUB,
        GZ,
        GIF,
        HTM,
        HTML,
        ICO,
        ICS,
        JAR,
        JPEG,
        JPG,
        JS,
        JSON,
        JSONLD,
        MID,
        MIDI,
        MJS,
        MP3,
        MP4,
        MPEG,
        MPKG,
        ODP,
        ODS,
        ODT,
        OGA,
        OGV,
        OGX,
        OPUS,
        OTF,
        PNG,
        PDF,
        PHP,
        PPT,
        PPTX,
        RAR,
        RTF,
        SH,
        SVG,
        TAR,
        TIF,
        TIFF,
        TS,
        TTF,
        TXT,
        VSD,
        WAV,
        WEBA,
        WEBM,
        WEBP,
        WOFF,
        WOFF2,
        XHTML,
        XLS,
        XLSX,
        XML,
        XUL,
        ZIP,
        _7Z
    };

    std::string to_string(const MIME &mime);
    MIME to_mime_type(const std::string &string);
}
