; Assembly part using x86-64

section .data
msg db "Hello World!", 13,10,0

section .text
bits 64
default rel ; Handles address relocation

global saxpy_asm ; Function name
extern printf

saxpy_asm:
	sub rsp, 8*5 ; Caller
	lea rcx, [msg]
	call printf
	add rsp, 8*5
	ret