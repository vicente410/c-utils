#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    String_Builder sb = {};

    sb_read_file(&sb, "main.c");
    sb_read_file(&sb, "str.h");

    String_View sv = sv_from_sb(sb);
    while (sv.count > 0) {
        String_View first = sv_trim(sv_split_delim(&sv, '\n'));
        printf("|"SV_FMT"|\n", SV_ARG(first));
    }
}
