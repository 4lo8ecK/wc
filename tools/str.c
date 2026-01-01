#include <windows.h>
#include "str.h"

uint64_t str_len(const char* str) {
    return MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0) - 1;
}

uint64_t wstr_len(const wchar_t* wstr) {
    return WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL) - 1;
}

const wchar_t* char_to_wchar(const char* txt) {
    uint64_t len = str_len(txt);
    if (len == 0) { return NULL; }
    
    wchar_t* wstr = (wchar_t*)malloc(len + 1);
    MultiByteToWideChar(CP_UTF8, 0, txt, -1, wstr, len);
    wstr[len] = L'\0';
    return wstr;
}

const char* wchar_to_char(const wchar_t* wtxt) {
    uint64_t len = wstr_len(wtxt);
    if (len == 0) { return NULL; }
    
    char* str = (char*)malloc(len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wtxt, -1, str, len, NULL, NULL);
    str[len] = '\0';
    return str;
}

uint64_t int_len(uint64_t number) {
    uint64_t count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

const wchar_t* int_to_wchar(uint64_t num) {
    uint64_t len = int_len(num);
    wchar_t* wstr = (wchar_t*)malloc(len + 1);
    _itow(num, wstr, 10);
    wstr[len] = L'\0';
    return wstr;
}

const char* int_to_char(uint64_t num) {
    uint64_t len = int_len(num);
    char* str = (char*)malloc(len + 1);
    itoa(num, str, 10);
    str[len] = '\0';
    return str;
}