// Include guard: prevents this file from being included twice
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>

std::string compress_string(const std::string& input);
std::string decompress_string(const std::string& input);

#endif