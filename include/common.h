// Heavily used features, types and things used across the whole project
// (c) s4pphic 2026
// SPDX-License-Identifier: APACHE-2.0

#pragma once

#include <stdbool.h>
#include <stdint.h>

#define MISC_MAX_MEMORY 0xFFFD

typedef enum {
    OP_NOP = 0,
    OP_MOV,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_AND,
    OP_NOT,
    OP_OR,
    OP_XOR,
    OP_JMP,
    OP_JZ,
    OP_JNZ,
    OP_CMP,
    OP_PUSH,
    OP_POP,
    OP_CALL,
    OP_RET,
    OP_SHL,
    OP_SHR,
    OP_INC,
    OP_DEC,
    OP_HLT,

    OP_COUNT
} OpCode;

typedef enum {
    REG_rA = 0,
    REG_rB,
    REG_rC,
    REG_rD,
    REG_SP,
    REG_IP,
    REG_FLAGS,

    REG_COUNT
} Register;

// An Instruction consists of three parts, its opcode and two arguments, or operands.
// operand_2 is larger than operand_1 for the sake of binary alignment, and instructions
// that let you jump to memory addresses / labels.
typedef struct {
    uint8_t opcode;
    uint8_t operand_1;
    uint16_t operand_2;
} Instruction;

// The actual "CPU" that'll run the code. Extremely basic, but gets the job done.
typedef struct {
    uint8_t regs[REG_COUNT];
    uint8_t mem[MISC_MAX_MEMORY];
    bool running;
} CPU;

// Mem-mapped I/O is convenient!

#define IO_STDOUT 0xFFFF    // Write a byte to stdout
#define IO_STDIN 0xFFFE     // Read a byte from stdin