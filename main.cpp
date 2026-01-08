#ifndef TEST_TWO
#include "wc/wc.hpp"
#endif
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstring>

std::string read_file(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        exit(1);
    }
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

inline std::string extract_filename(const std::string& path) {
    static std::filesystem::path pt(path);
    return pt.filename().string();
}

#ifdef TEST3
void classic_print(const std::string& path) {
    std::string text = read_file(path);
    printf("%s %s %s %s\n", lines_count(text), words_count(text), bytes_count(text), extract_filename(path));
    /*std::cout << lines_count(text)
            << " " << words_count(text)
            << " " << bytes_count(text)
            << " " << extract_filename(path)
            << std::endl;*/
}
#endif

void print_version() {
    std::cout << APP_NAME << " " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
}


inline void print_options(const std::string& path, const std::vector<const char*>& options) {
    std::string text = read_file(path);
    
    for (size_t i = 0; i < options.size(); i++) {
        const char* opt = options[i];
        if (strcmp(opt, LINES_OPT) == 0 || strcmp(opt, LINES_OPT_SHORT) == 0) {
            std::cout << lines_count(text);
        }
        else if (strcmp(opt, WORDS_OPT) == 0 || strcmp(opt, WORDS_OPT_SHORT) == 0) {
            std::cout << words_count(text);
        }
        else if (strcmp(opt, BYTES_OPT) == 0 || strcmp(opt, BYTES_OPT_SHORT) == 0) {
            std::cout << bytes_count(text);
        }
        else if (strcmp(opt, CHARS_OPT) == 0 || strcmp(opt, CHARS_OPT_SHORT) == 0) {
            std::cout << characters_count(text);
        }
        else if (strcmp(opt, MAX_LINE_LEN_OPT) == 0 || strcmp(opt, MAX_LINE_LEN_OPT_SHORT) == 0) {
            std::cout << longest_line_size(text);
        }
        std::cout << " ";
    }
    std::cout << extract_filename(path) << std::endl;
}

int main(int argc, char** argv) {
    printf("argc = %d\n", argc);
    std::vector<const char*> options;
    std::string path;
    if (argc == 1) {
        exit(0);
    }
    for (int i = 1; i < argc; i++) {
        // argument is option
        printf("argv[%d] = %s\n", i, argv[i]);
        if (argv[i][0] == '-') {
            if (argc = 2 && (!strcmp(argv[i], VER_OPT) || !strcmp(argv[i], VER_OPT_SHORT))) {
                print_version();
            }
            else options.push_back(argv[i]);
        }
        else {
            path = std::string(argv[i]);
            // printf("argv[%d] = %s\t| %s\n", i, argv[i], path.c_str());

        }
    }
    if (options.empty()) {
        options = {LINES_OPT, WORDS_OPT, BYTES_OPT};
    }
    if (path.empty()) {
        printf("empty path\n");
    }
    printf("path - '%s'\n", path.c_str());
    printf("options:\n");
    for (size_t i = 0; i < options.size(); i++) {
        printf("%lld - '%s'\n", i, options[i]);
    }
    print_options(path, options);
      
#pragma region tests
#ifdef TEST3
    std::string path = "C:/dirname/untitled.txt";
    std::string text = "Line number one\nsecond line\nanother line with number three";

    classic_print(path, text);
    classic_print(extract_filename(path), text);
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
#pragma endregion
}