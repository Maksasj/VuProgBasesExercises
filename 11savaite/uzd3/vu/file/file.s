	.file	"file.c"
	.text
	.globl	saveCount
	.bss
	.align 4
saveCount:
	.space 4
	.globl	loadCount
	.align 4
loadCount:
	.space 4
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	leaq	32(%rbp), %rax
	movq	16(%rbp), %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movl	32(%rbp), %eax
	movslq	%eax, %rdx
	movq	24(%rbp), %rax
	movq	16(%rbp), %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movl	saveCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, saveCount(%rip)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rax
	movq	16(%rbp), %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	movslq	%eax, %rdx
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	movq	16(%rbp), %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movl	loadCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, loadCount(%rip)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.3.0"
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
