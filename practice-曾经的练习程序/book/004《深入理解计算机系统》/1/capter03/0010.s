	.file	"0010.c"
	.text
	.globl	call_proc
	.type	call_proc, @function
call_proc:
.LFB0:
	.cfi_startproc
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movq	$1, 16(%rsp)
	movl	$2, 24(%rsp)
	movw	$3, 28(%rsp)
	movb	$4, 31(%rsp)
	leaq	31(%rsp), %rax
	movq	%rax, 8(%rsp)
	movl	$4, (%rsp)
	leaq	28(%rsp), %r9
	movl	$3, %r8d
	leaq	24(%rsp), %rcx
	movl	$2, %edx
	leaq	16(%rsp), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	proc
	movslq	24(%rsp), %rdx
	addq	16(%rsp), %rdx
	movswl	28(%rsp), %eax
	movsbl	31(%rsp), %ecx
	subl	%ecx, %eax
	cltq
	imulq	%rdx, %rax
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	call_proc, .-call_proc
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
