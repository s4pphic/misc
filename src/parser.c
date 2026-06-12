#include "asm/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

int parse(const char* source, Line** out_lines, uint32_t out_count) {
    FILE* f = fopen(source, "r");
    if (!f) {
        fprintf(stderr, "Error: couldn't open file \"%s\"\n", source);
        return 1;
    }

    // TODO: 
    //  - allocate lines, fixed cap maybe?
    //  - read line by line with fgets
    //  - strip comments (everything after ';' OR '#')
    //  - skip blank lines
    //  - detect label definitions (token ends with ':')
    //  - tokenize remaining words into opcodes, registers, immediates
    //  - populate out_lines and out_count

    fclose(f);
    return 0;
}