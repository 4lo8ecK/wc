#include "wc/wc.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    

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