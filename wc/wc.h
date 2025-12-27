#include <stdint.h>

#define OPTIONS

#ifdef OPTIONS

#define LINES_OPT_SHORT "-l"
#define LINES_OPT "--lines"

#define WORDS_OPT_SHORT "-w"
#define WORDS_OPT "--words"

#define BYTES_OPT_SHORT "-b"
#define BYTES_OPT "--bytes"

#define CHARS_OPT_SHORT "-c"
#define CHARS_OPT "--chars"

#define MAX_LINE_LEN_OPT_SHORT "-L"
#define MAX_LINE_LEN_OPT "--max-line-length"

/* Additional options */
#define VER_OPT_SHORT "-v"
#define VER_OPT "--version"

#endif

/* Functions */
uint32_t lines_count(const char* text);
uint32_t words_count(const char* text);
uint64_t bytes_count(const char* text);
uint64_t characters_count(const char* text);
uint32_t longest_line_size(const char* text);

