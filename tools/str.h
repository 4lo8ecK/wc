#ifndef _TOOLS_STR_H
#define _TOOLS_STR_H

#include <stdint.h>

uint64_t str_len(const char* str);
uint64_t wstr_len(const wchar_t* wstr);

const wchar_t* char_to_wchar(const char* txt);
const char* wchar_to_char(const wchar_t* wtxt);

uint64_t int_len(uint64_t number);
const wchar_t* int_to_wchar(uint64_t num);
const char* int_to_char(uint64_t num);

#endif