	global	my_memset:function
	global	memset:function
	section	.text
my_memset:
memset:
	; parameters (rdi: ptr, esi: substitute byte, rdx: size)
	; local variables
	xor	rax, rax		; idx
	jmp	.LCOND

.LBODY:
	mov	BYTE [rdi+rax], sil
	inc	rax

.LCOND:
	cmp	rdx, rax
	ja	.LBODY

.END:
	ret
