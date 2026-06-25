#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    String_View sv = sv_from_cstr("Hello world, how are you doing in this fine day?");
    while (sv.length > 0) {
        String_View first = sv_split_delim(&sv, ' ');
        if (first.length > 0) printf("|"SV_FMT"|\n", SV_ARG(first));
    }
}
