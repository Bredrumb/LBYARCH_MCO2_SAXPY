section .text
bits 64
default rel

global saxpy_asm

saxpy_asm:
    ;write your code here
    
    ; int n (size of vector) is passed to ECX 
    ; float A (scalar variable) is passed to xmm1
    ; float* X (first vector) is passed to r8 (address)
    ; float* Y (second vector) is passed to r9 (address)
    ; float* Z (result vector) should be passed to r10 ; do by (mov r10, [rbp+32])

    push rsi
    push rbp 

    mov rbp, rsp
    add rbp, 16
    add rbp, 8
    mov rdi, 0
    mov r10, [rbp+32] ; Initialize r10 as Z[]
    movss xmm7, xmm1 ; Initialize xmm7 as A

    L1: 

        movss xmm5, [r8+rdi*4]      ; Initialize X[i] as xmm5
        mulss xmm5, xmm7            ; A*X[i]
        movss xmm8, [r9+rdi*4]      ; Initialize Y[i] as xmm8
        addss xmm5, xmm8            ; +Y[i]
        ; Now answer is in xmm5
    
        ; Move answer to Z[i]
        movss [r10+rdi*4], xmm5
    
        INC rdi
        DEC ECX

    JNZ L1
    
    pop rbp
    pop rsi
    ret