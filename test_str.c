#include <stdio.h>

#include "sy_str.h"

int main() {
    sy_str s = str("hello");
    sy_str splits[10] = {0};
    size_t num_splits = sy_str_split(s, 'e', splits);
    puts("OK");
    return 0;
}
