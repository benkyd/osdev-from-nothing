;;kernel.asm
bits 32                      ; tells nasm to use 32 bit
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero

global start
extern kmain

start:
    cli                       ; blocks interupts i think
    mov ESP, stack_space      ; sets stack pointer
    call kmain                ; calls kmain c++ function
    hlt                       ; halts CPU

section .bss
resb 8192                     ; 8 kb stack
stack_space:
