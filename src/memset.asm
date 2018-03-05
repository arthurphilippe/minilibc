		global	memset:function
		section	.text
memset:
	push	rbp
	mov	rbp, rsp

	; parameters
	mov	QWORD [rbp-24], rdi	; ptr
	mov	DWORD [rbp-28], esi	; int replacement byte
	mov	QWORD [rbp-40], rdx	; size_t n-bytes

	; local variables
	mov	DWORD [rbp-4], 0	; idx
	jmp	.LCOND

.LBODY:
	movsx	rdx, DWORD [rbp-4]	; <-- idx
	mov	rax, QWORD [rbp-24]	; <-- ptr
	add	rax, rdx		; <-- s[idx]
	mov	edx, DWORD [rbp-28]	; <-- replacement byte
	mov	BYTE [rax], dl
	add	DWORD [rbp-4], 1

.LCOND:
	movsx	rax, DWORD [rbp-4]	; current index as QWORD
	cmp	QWORD [rbp-40], rax
	ja	.LBODY

.END:
	pop	rbp
	ret
