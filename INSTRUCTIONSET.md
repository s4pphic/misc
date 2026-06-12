# MISC Instruction Set

The MISC ISA is _four bytes per instruction:_ 8 bits for the opcode, 8 bits for the first operand and 16 bits for the second operand.

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
