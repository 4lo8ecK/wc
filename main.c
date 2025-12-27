#ifndef TEST
#include "wc/wc.h"
#endif

#include <string.h>
#include <stdio.h>
#include <locale.h>

#define TEST
#ifdef TEST
int get_len(const unsigned char* text) {
    int count = 0;

    for(;;) {
        char chr = text[count];
        printf("%d - %d\n", count, chr);
        if (chr == '\0') {
            break;
        }
        count++;
    }

    return count;
}
#endif

int main() {

#ifdef TEST
    setlocale(LC_ALL, ".UTF-8");

    #if 1
    
    const char* test_line_en = "Test text with len = 23";
    int len1_en = strlen(test_line_en);
    int len2_en = sizeof(*test_line_en);
    
    printf("%s\n-> %d %d\n", test_line_en, len1_en, len2_en);
    get_len(test_line_en);
    
    const char* test_line_ru = "Текст в длину = 18";
    int len1_ru = strlen(test_line_ru);
    int len2_ru = sizeof(test_line_ru[0]);
    
    printf("%s\n-> %d %d\n", test_line_ru, len1_ru, len2_ru);
    
    get_len(test_line_ru);
    #endif

#endif
}