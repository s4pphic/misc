// Parser, takes in source text and tokenizes it into something the assembler can work with
// (c) s4pphic 2026
// SPDX-License-Identifier: APACHE-2.0

#pragma once

#include "../common.h"
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
    TOKEN_OPCODE,
    TOKEN_REGISTER,
    TOKEN_IMMEDIATE,
    TOKEN_LABEL_DEF,    // "_start:"
    TOKEN_LABEL_REF,    // "_start" as a jmp target
} TokenType;

typedef struct {
    TokenType type;
    union {
        uint8_t  regsiter;
        uint16_t immediate;
        uint8_t  opcode;
        char     label[64];
    };
} Token;

typedef struct {
    Token   tokens[3];  // opcode + up to 2 operands
    uint8_t count;
} Line;

int parse(const char* source, Line** out_lines, uint32_t out_count);