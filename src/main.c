// Entry point, flag parsing and dispatch
// (c) s4pphic 2026
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "asm/parser.h"

static void usage(const char* prog) {
    fprintf(stderr, "Use:\n");
    fprintf(stderr, "  %s -a <source.misc>   assemble source to out.bin\n", prog);
    fprintf(stderr, "  %s -r <program.bin>   run a compiled binary\n", prog);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Usually against hardcoding stuff but this prog is so damn small

    const char* flag = argv[1];
    const char* file = argv[2];

    if (strcmp(flag, "-a") == 0) {
        Line **lines;
        uint32_t out_count = 0;
        parse(file, lines, out_count);
    } else if (strcmp(flag, "-r") == 0) {
        return 7;
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}