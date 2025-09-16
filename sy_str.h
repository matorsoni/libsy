#include <stddef.h>

typedef struct sy_str sy_str;
struct sy_str {
    char*  ptr;
    size_t len;
};

#define str(s) (sy_str){.ptr = (s), .len = sizeof((s))}

size_t sy_str_split(sy_str s, char divisor, sy_str* output) {
    size_t num_splits = 0;
    sy_str split = {.ptr = s.ptr, .len = 0};
    for (size_t i = 0; i < s.len; ++i) {
        if (s.ptr[i] == divisor) {
            *output++ = split;
            num_splits++;
            i++;
            split.ptr = &s.ptr[i];
            split.len = 0;
        }
        else {
            split.len++;
        }
    }
    return num_splits;
}
