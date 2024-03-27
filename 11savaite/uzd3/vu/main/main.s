	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "wb\0"
.LC1:
	.ascii "file1.bin\0"
.LC2:
	.ascii "file2.bin\0"
.LC3:
	.ascii "all good\0"
.LC4:
	.ascii "something\342\200\231s wrong\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$240, %rsp
	.seh_stackalloc	240
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	call	rand
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -64(%rbp,%rax,4)
	call	rand
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -112(%rbp,%rax,4)
	call	rand
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -160(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$9, -4(%rbp)
	jle	.L3
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	leaq	-64(%rbp), %rdx
	movq	-16(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	leaq	-160(%rbp), %rdx
	movq	-16(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	leaq	-164(%rbp), %rcx
	leaq	-176(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -24(%rbp)
	leaq	-112(%rbp), %rdx
	movq	-24(%rbp), %rax
	movl	$10, %r8d
	movq	%rax, %rcx
	call	saveToFile
	leaq	-180(%rbp), %rcx
	leaq	-192(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	leaq	-196(%rbp), %rcx
	leaq	-208(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L4
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L4
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L5
.L4:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L5:
	movl	$0, %eax
	addq	$240, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.3.0"
	.def	time;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.loadCount, "dr"
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
	.section	.rdata$.refptr.saveCount, "dr"
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
