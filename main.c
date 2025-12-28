#ifndef TEST
#include "wc/wc.h"
#endif

#include <windows.h>
#include <stdio.h>
#include <locale.h>

#include <time.h>

#define TEST
#ifdef TEST

DWORD str_len(LPCSTR str) {
    return MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0) - 1;
}

DWORD wstr_len(LPCWSTR wstr) {
    return WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL) - 1;
}

LPCWSTR char_to_wchar(LPCSTR txt) {
    DWORD len = str_len(txt);
    if (len == 0) { return NULL; }
    
    LPWSTR wstr = (LPWSTR)malloc(len + 1);
    MultiByteToWideChar(CP_UTF8, 0, txt, -1, wstr, len);
    wstr[len] = L'\0';
    return wstr;
}

LPCSTR wchar_to_char(LPCWSTR wtxt) {
    DWORD len = wstr_len(wtxt);
    if (len == 0) { return NULL; }
    
    LPSTR str = (LPSTR)malloc(len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wtxt, -1, str, len, NULL, NULL);
    str[len] = '\0';
    return str;
}

DWORD int_len(DWORD number) {
    DWORD count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

LPCWSTR int_to_wchar(DWORD num) {
    DWORD len = int_len(num);
    LPWSTR wstr = (LPWSTR)malloc(len + 1);
    _itow(num, wstr, 10);
    wstr[len] = L'\0';
    return wstr;
}

LPCSTR int_to_char(DWORD num) {
    DWORD len = int_len(num);
    LPSTR str = (LPSTR)malloc(len + 1);
    itoa(num, str, 10);
    str[len] = '\0';
    return str;
}


#endif

int main() {
    #ifdef TEST
    // time_t start_time = time(NULL);
    setlocale(LC_ALL, "");

    #if 1
    // time_t str_beg_time = time(NULL);
    LPCSTR str = "Пример текста, text example";
    LPCWSTR wstr = L"Пример текста, text example";
    LPCWSTR wstr1 = char_to_wchar(str);
    DWORD num = 123416;
    // time_t str_end_time = time(NULL);
    
    // time_t print_time_beg = time(NULL);
    for (int i = 0; i < 50; i++)
    {
        printf("Iteration %d\n", i);
        printf("\t%ld\n", str_len("abcdef"));
        printf("\t%ld\n", wstr_len(L"abcdef"));
        printf("\t%ls\n", int_to_wchar(num));
        printf("\t%s\n", str);
        printf("\t%S\n", wstr);
        printf("\t%S\n", wstr1);       
        printf("\n");
    }
    
    #endif
#endif
}