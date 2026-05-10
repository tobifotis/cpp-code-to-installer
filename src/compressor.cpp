#include "compressor.h"
#include <zlib.h>  // Provided by Conan
#include <stdexcept>
#include <vector>

std::string compress_string(const std::string& input) {
    // Ask zlib how big the output buffer needs to be
    uLongf compressed_size = compressBound(input.size());
    std::vector<char> buffer(compressed_size);

    int result = compress(
        reinterpret_cast<Bytef*>(buffer.data()),
        &compressed_size,
        reinterpret_cast<const Bytef*>(input.data()),
        input.size()
    );

    if (result != Z_OK) {
        throw std::runtime_error("Compression failed with error code: " + std::to_string(result));
    }

    return std::string(buffer.data(), compressed_size);
}

std::string decompress_string(const std::string& input) {
    // Allocate 10x input size since decompressed data is much larger
    uLongf decompressed_size = input.size() * 10;
    std::vector<char> buffer(decompressed_size);

    int result = uncompress(
        reinterpret_cast<Bytef*>(buffer.data()),
        &decompressed_size,
        reinterpret_cast<const Bytef*>(input.data()),
        input.size()
    );

    if (result != Z_OK) {
        throw std::runtime_error("Decompression failed with error code: " + std::to_string(result));
    }

    return std::string(buffer.data(), decompressed_size);
}