#include <iostream>
#include <string>
#include "compressor.h"

int main() {
    std::string original = "Hello from cpp-code-to-installer! "
                           "This project demonstrates the full C++ delivery chain: "
                           "Conan fetches dependencies, CMake builds the project, "
                           "Jenkins automates the pipeline, and InstallAnywhere "
                           "packages it into an installer.";

    std::cout << "=== C++ Compression Demo ===" << std::endl;
    std::cout << "Original size: " << original.size() << " bytes" << std::endl;
    std::cout << "Original text: " << original << std::endl;
    std::cout << std::endl;

    std::string compressed = compress_string(original);
    std::cout << "Compressed size: " << compressed.size() << " bytes" << std::endl;

    std::string decompressed = decompress_string(compressed);
    std::cout << "Decompressed size: " << decompressed.size() << " bytes" << std::endl;
    std::cout << "Decompressed text: " << decompressed << std::endl;
    std::cout << std::endl;

    // Verify the round-trip: original should match decompressed
    if (original == decompressed) {
        std::cout << "SUCCESS: Round-trip compression worked!" << std::endl;
    } else {
        std::cout << "ERROR: Decompressed text doesn't match original!" << std::endl;
    }

    return 0;
}