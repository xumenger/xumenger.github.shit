	.file	"0003.c"
	.text
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB0:
	.cfi_startproc
	subl	$100, %esi
	cmpl	$6, %esi
	ja	.L8
	movl	%esi, %esi
	jmp	*.L7(,%rsi,8)
	.section	.rodata
	.align 8
	.align 4
.L7:
	.quad	.L3
	.quad	.L8
	.quad	.L4
	.quad	.L5
	.quad	.L6
	.quad	.L8
	.quad	.L6
	.text
.L3:
	leal	(%rdi,%rdi,2), %eax
	leal	(%rdi,%rax,4), %eax
	ret
.L4:
	addl	$10, %edi
.L5:
	leal	11(%rdi), %eax
	ret
.L6:
	movl	%edi, %eax
	imull	%edi, %eax
	ret
.L8:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
