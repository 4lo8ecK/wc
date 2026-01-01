#ifdef TEST21
#include "wc/wc.h"
#endif
// #define TEST2

#ifdef TEST
#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <wc.h>
#include <str.h>
#endif

#ifdef TEST2
#include <stdio.h>
#include <locale.h>
#include <wc.h>
#include <str.h>
#endif

#define TEST3
#ifdef TEST3

#include <stdio.h>
#include <locale.h>
#include <wc.h>
#include <str.h>

#endif

int main() {
    setlocale(LC_ALL, "");
    // const char* test_text = "Test line 1\nSecond line is bigger\nanother line\nthat means str has four lines";
    // int count = lines_count(test_text);
    // printf("%d", count);

    // const char* text = "  Just -  test -- of  this fucking function";
    // uint64_t res = words_count(text);

    // printf("%s\n", text);
    // printf("count - %d\n", res);

    

    #ifdef TEST2
    setlocale(LC_ALL, "");
    const char* tst = "Проверка";
    const wchar_t* wtst = L"Проверка";
    printf("Test1 - %s\n", tst);
    printf("Test2 - %S\n", char_to_wchar(tst));
    printf("Test3 - %S\n", wtst);

    #endif
    #ifdef TEST
    setlocale(LC_ALL, "");

    #if 1
   
    unsigned long num = 123416;
    const char* txt = "абвгдеёжзи";
    const wchar_t* wtxt = L"абвгдеёжзи";

    for (int i = 0; i < 1; i++)
    {
        printf("Iteration %d\n", i);
        printf("length of \x1b[0;3;33m\"%S\"\x1b[0m is \x1b[0;3;96m10\x1b[0\n", char_to_wchar(txt));
        printf("\x1b[1;33mstr_len(\x1b[0;3;33m\"%S\"\x1b[1;33m)\x1b[0m\t -> %ld\n", wtxt, str_len(txt));
        printf("\x1b[1;33mwstr_len(\x1b[0;3;33m\"%S\"\x1b[1;33m)\x1b[0m\t -> %ld\n", wtxt, wstr_len(char_to_wchar(txt)));
        printf("\x1b[1;33mint_to_char(\x1b[0;3;96m123416\x1b[0;1;33m)\x1b[0m\t -> %ls\n", int_to_wchar(num));
        printf("\n");
    }
    
    #endif
    #endif
}