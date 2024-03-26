; Assembly part using x86-64

;section .data
;msg db "Hello World!", 13,10,0

;section .text
;bits 64
;default rel ; Handles address relocation

;global saxpy_asm ; Function name
;extern printf

;saxpy_asm:
;	sub rsp, 8*5 ; Caller
;	lea rcx, [msg]
;	call printf
;	add rsp, 8*5
;	ret



	section .data
    A_float dd 0.0        ; Scalar A
    X_vector dd 0.0, 0.0, 0.0   ; Input vector X
    Y_vector dd 0.0, 0.0, 0.0   ; Input vector Y
    Z_result dd 0.0, 0.0, 0.0   ; Result vector Z

section .text
    global saxpy_asm

saxpy_asm:
    
    push rbp
    mov rbp, rsp

    
    movss xmm0, dword [A_float]

    
    mov ecx, 3          ; Vector length (assuming 3 elements)
saxpy_loop:
    
    movss xmm1, dword [X_vector + ecx*4 - 4]

    
    movss xmm2, dword [Y_vector + ecx*4 - 4]

    
    mulss xmm1, xmm0    ; A * X[i]
    addss xmm1, xmm2    ; A * X[i] + Y[i]

    
    movss dword [Z_result + ecx*4 - 4], xmm1

    
    loop saxpy_loop

    
    mov rsp, rbp
    pop rbp
    ret
