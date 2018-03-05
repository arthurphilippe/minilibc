my_memset:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi	; ptr
        mov     DWORD PTR [rbp-28], esi ; int
        mov     QWORD PTR [rbp-40], rdx ; size_t
        mov     DWORD PTR [rbp-4], 0	; idx
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-4]
        movsx   rdx, eax
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        mov     edx, DWORD PTR [rbp-28]
        mov     BYTE PTR [rax], dl
        add     DWORD PTR [rbp-4], 1
.L2:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        cmp     QWORD PTR [rbp-40], rax
        ja      .L3
        nop
        pop     rbp
        ret
