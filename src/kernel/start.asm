; ToriX - TORres Interactive eXecution
; Copyright (c) 2008 Devin Torres
; Licensed under the MIT license.

[bits 32]

[global start]
%ifdef CYGWIN
[extern _main]
%else
[extern main]
%endif

[section .data]

; The Global Descriptor Table (GDT); this tells us where all the segments (now
; selectors) are:
gdt:
	; Null descriptor:
	dw 0	; limit 15:0
	dw 0	; base 15:0
	db 0	; base 23:0
	db 0	; type
	db 0	; limit 19:16, flags
	db 0	; base 31: 24

	; Unused descriptor:
	dw 0
	dw 0
	db 0
	db 0
	db 0
	db 0

	; Data segment descriptor:
	DATA_SELECTOR equ $-gdt	; The data selector; an index into the GDT.
	dw 0xFFFF	; limit of 4GB
	dw 0		; base 0
	db 0
	db 0x92		; present, ring 0, data, expand-up, writable
	db 0xCF		; page-granular, 32-bit
	db 0

	; Code segment descriptor:
	CODE_SELECTOR equ $-gdt	; The code selector; an index into the GDT.
	dw 0xFFFF	; limit of 4GB
	dw 0		; base 0
	db 0
	db 0x9A		; present, ring 0, code, non-conforming, readable
	db 0xCF		; page-granular, 32-bit
	db 0
gdt_end:

; Pointer to the GDT:
gdtr:
	dw gdt_end - gdt - 1	; Size of the GDT
	dd gdt					; Linear address of GDT base

[section .text]

start:
	; Load the new GDT:
	lgdt	[gdtr]

	; Call the kernel and let it take over:
%ifdef CYGWIN
	call	_main
%else
	call	main
%endif

	; If the kernel wasn't loaded, freeze:
	jmp	$
