	global	memmove:function
	section	.text
memmove:
	; parameters (rdi: dest, rsi: source, rdx: size)
	; local variables
	cmp	rdi, rsi
	je	.END
	jg	.REVERSE

	xor	rax, rax		; idx
	jmp	.NLCOND

; memcpy classic
.NLBODY:
	mov	cl, BYTE [rsi+rax]
	mov	BYTE [rdi+rax], cl
	inc	rax

.NLCOND:
	cmp	rdx, rax
	ja	.NLBODY
	jmp	.END

; memcpy reverse
.REVERSE:
	mov	rax, rdx
	dec	rax
	jmp 	.RLCOND

.RLBODY:
	mov	cl, BYTE [rsi+rax]
	mov	BYTE [rdi+rax], cl
	dec	rax

.RLCOND:
	cmp	rax, 0
	jge	.RLBODY

; end
.END:
	mov	rax, rdi
	ret
