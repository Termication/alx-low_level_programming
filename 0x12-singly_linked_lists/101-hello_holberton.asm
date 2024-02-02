global main
extern printf

section .data
    format db "Hello, Holberton", 0xA

section .text
main:
    mov   edi, format
    xor   eax, eax
    call  printf
    mov   eax, 0
    ret
