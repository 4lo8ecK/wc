#ifndef TEST_TWO
#include "wc/wc.hpp"
#endif
#include <iostream>
#include <vector>
#include <fstream>

void classic_print(const std::string& filename, const std::string& text) {
    std::cout << lines_count(text)
            << " " << words_count(text)
            << " " << bytes_count(text)
            << " " << filename
            << std::endl;
}

std::string read_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) { return ""; }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

int main(int argc, char* argv[]) {

    if (argc > 1) {
        std::string filename = argv[1];
        std::string file_content = read_file(filename);
        classic_print(filename, file_content);
    }

#ifdef TEST3
    std::string filename = "untitled.txt";
    std::string text = "Line number one\nsecond line\nanother line with number three";

    classic_print(filename, text);
#endif
#ifdef TEST_TWO
    std::cout << "\v\v\tTest text" << std::endl;
#endif
#ifdef TEST_ONE
    std::string testline = "Line number one\nsecond line\nanother line with number three";
    std::cout << "\x1b[1;33m" << testline << "\x1b[0m" << std::endl;
    std::cout << lines_count(testline) << std::endl;
    std::cout << words_count(testline) << std::endl;
    std::cout << bytes_count(testline) << std::endl;
    std::cout << characters_count(testline) << std::endl;
    std::cout << longest_line_size(testline) << std::endl;
#endif
}