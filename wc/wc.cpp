#include "wc.hpp"

#include <windows.h>
#include <algorithm>
#include <sstream>

uint32_t lines_count(const std::string &text) {
    uint32_t count = std::count(text.begin(), text.end(), '\n');
    if (!text.empty() && text.back() != '\n') {
        count++;
    }
    return count;
}

uint32_t words_count(const std::string &text) {
    std::stringstream ss(text);
    std::string word;
    uint32_t count = 0;
    while (ss >> word) {
        ++count;
    }
    return count;
}

uint64_t bytes_count(const std::string &text) {
    return text.size();
}

uint64_t characters_count(const std::string &text) {
    return MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, NULL, 0) - 1;
}

uint32_t longest_line_size(const std::string& text) {
    std::istringstream iss(text);
    std::string line;
    uint32_t max_len = 0;
    while (std::getline(iss, line)) {
        uint32_t size = line.size();
        if (size > max_len)
        {
            max_len = size;
        }
    }
    return max_len;
}