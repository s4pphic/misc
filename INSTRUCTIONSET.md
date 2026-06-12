# MISC Instruction Set

The MISC ISA is _four bytes per instruction:_ 8 bits for the opcode, 8 bits for the first operand and 16 bits for the second operand.

MISC supports two kinds of comments; comments prefaced with `;` and with `#` and you can use both across the same codebase. I selected those based on most asm families using either of them, for developer comfort.

---

```
mov source, desti
add source, desti
sub source, desti
mul source, desti
div source, desti
and a, b
not a, b
or a, b
xor a, b
jmp line
jz source, line
jnz source, line
cmp a, b
push reg
pop reg
call label
ret
shl a
shr a
nop
inc a
dec a
```
