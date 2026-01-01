#if 0
// HIKA-SOFT
// my 'wc' analog
// VER - 1.0
#endif

#include "wc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <str.h>

#define IN 1
#define OUT 0

uint64_t __words_count(const char* s) {
    uint64_t count = 0;
    int state = OUT;
    for (uint64_t i = 0; i < str_len(s); i++) {
        if (isspace(s[i])) {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            count++;
        }
    }
    return count;
}
            
#if 0
static char** str_vec(const char* s, char sep, int* count) {
    int _count = 0;
    char** vec = (char**)malloc(sizeof(char*));
    int line_len = 0;
    char* line = (char*)malloc(sizeof(char));
    line[0] = '\0';

    for (int i = 0; i != '\0'; i++) {
        if (s[i] != sep) {
            vec[_count] = (char*)malloc((line_len + 1) * sizeof(char));
            strcpy(vec[_count], line);
            vec[_count][line_len] = '\0';
            realloc(line, 1);
            line[0] = '\0';
            line_len = 0;
            _count++;
        }
        else {
            printf("%s", line);
            realloc(line, line_len + 1);
            line[line_len] = s[i];
            line_len++;
        }
    }
    free(line);
    count = &_count;
    return vec;
}
#endif

/* it counts empty lines too */
uint32_t lines_count(const char* text) {
    uint32_t res = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            res++;
        }
    }
    return res;
}

uint64_t words_count(const char* text) {
    return __words_count(text);
}

uint64_t bytes_count(const char* text) {
    return strlen(text);
}

uint64_t characters_count(const char* text) {
    return str_len(text);
}

// uint32_t longest_line_size(const char* text);