; ToriX - TORres Interactive eXecution
; Copyright (c) 2008 Devin Torres
; Licensed under the MIT license.

[bits 16]
[org 0x7C00]

%include "print.asm"

[section .text]

jmp start

; Various messages that are to be printed throughout the boot process:
boot_msg		db	"Booting ToriX OS.", 0
read_error_msg	db	0xD, 0xA, "Error reading the disk.", 0xD, 0xA, 0
detect_cpu_msg	db	0xD, 0xA, "Checking for a 486+ processor... ", 0
found_486_msg	db	"found.", 0xD, 0xA, 0
need_486_msg	db	0xD, 0xA, "A 486+ processor is requierd to run ToriX.", 0
reboot_msg		db	0xD, 0xA, "Press any key to reboot: ", 0
dot				db	".", 0

; How many times the floppy reading procedure should try to read again if
; there is an error:
retry_count	db	3

; The amount of sectors the kernel occupies:
sectors		dw	16

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

.486	; Generate 486+ instructions only

; Clear the screen:
clear_screen:
	mov ax, 0x3	; Set text-mode 3
	sti			; Enable interrupts
	int 0x10	; Invoke the BIOS => the screen is cleared
	cli			; Disable interrupts
	ret

; Print ds:si to the screen:
print_msg:
	pusha
.nextchar:
	lodsb			; Load the byte at ds:si into al
	or al, al		; Test if the character is NULL (end of the string)...
	jz .done		; ...if so, stop printing and return.
	mov ah, 0xE	; Command 'BIOS teletype'
	mov bx, 0x7	; Character attribute (white text)
	sti				; Enable interrupts
	int 0x10		; Invoke the BIOS => the character is printed
	cli				; Disable interrupts
	jmp	.nextchar	; Continue printing the rest of the characters
.done:
	popa
	ret

; Clear the keyboard buffer:
clear_buf:
	xor	cx, cx
	in al, 0x64 		; Get input from the keyboard status port
	test al, 0x02 		; Test the buffer full flag
	loopnz clear_buf	; Loop until the buffer is empty
	ret

; Read from the floppy:
read_floppy:
	push bx
	push cx
.try_again:
	mov al, 0x13	; Read a maximum of 18 sectors
	sub al, bl		; Substract the first sector (to prevent wrap-around)
	xor ah, ah		; Don't read more than required
	cmp ax, cx
	jl .shorten
	mov ax, cx
.shorten:
	mov cx, bx		; Sector/cylinder number to read from
	mov bx, 0x8000	; Buffer address
	mov ah, 0x2		; Command 'read sectors'
	push ax
	sti				; Enable interrupts
	int 0x13		; Invoke the BIOS => The computer reads the floppy
	cli				; Disable interrupts
	pop ax			; Reload al manually
	jnc .success	; No error => proceed as usual
	dec byte [retry_count]
	jz .fail
	xor ah, ah		; Reset the disk controller
	sti				; Enable interrupts
	int 0x13		; Invoke the BIOS => the floppy is read from
	cli				; Disable interrupts
	jmp	.try_again	; Retry
.success:
	mov byte [retry_count], 3	; Reload retry_count
	print dot
	mov esi, 0x8000	; Source
	xor ecx, ecx
	mov cl, al		; Copy the number of read sectors (al)...
	shl cx, 0x7	; ...of size 128*4 bytes...
	rep a32 movsd	; ...to destination (edi)
	pop cx
	pop bx
	xor dh, 0x1	; Read: next head
	jnz .bar6
	inc bh			; Read: next cylinder
.bar6:
	mov bl, 0x1	; Read: sector 1
	xor ah, ah
	sub cx, ax		; Substract the number of read sectors
	jg read_floppy	; Sectors left to read?
	ret
.fail:
	; Print an error message, wait for a keypress, and reboot:
	print read_error_msg
	print reboot_msg

	xor ax, ax
	sti			; Enable interrupts
	int 0x16	; Invoke the BIOS => the computer waits for a key
	int 0x19	; Invoke the BIOS => the computer reboots
	cli			; Disable interrupts
	hlt			; Halt the CPU (if we even get here, that is)

start:
	; Disable interrupts from the beginning:
	cli

	; Create a stack:
	xor ax, ax
	mov ss, ax
	mov sp, 0xFFFF	; 64Kb stack

	; Clear the screen and print the boot message:
	call clear_screen
	print boot_msg

	; Enable the A20 gateway:
	call clear_buf	; Wait until the keyboard buffer is empty

	mov al, 0xD1	; Keyboard: write to the output port
	out 0x64, al	; Output command to the keyboard

	call clear_buf	; Wait until the keyboard buffer is empty again

	mov al, 0xDF	; Keyboard: set A20
	out 0x60, al	; Send it to the keyboard controller
	mov cx, 0x14

	call clear_buf	; Wait 25 sec. for A20 to be enabled

	nop
	nop

	; Enter "unreal" mode, but first save the segment registers:
	push ds
	push es

	; Load a temporary GDT (we will load another one in the second stage):
	lgdt [gdtr]

	; Switch to temporary 32-bit protected mode:
	mov eax, cr0
	or al,1
	mov cr0, eax

[bits 32]
	; Load a 32-bit value into a few segment registers:
	mov bx, DATA_SELECTOR
	mov ds, bx
	mov es, bx

	; Switch back to real mode (but with 32-bit addresses, i.e. "unreal"
	; mode):
	dec al
	mov cr0, eax

[bits 16]
	; Segment registers back to old values:
	pop es
	pop ds

	; Read in the second half of this stage of the bootloader:
	xor dx, dx			; Start at head 0
	mov bx, 0x2		; Start at sector 2 for the second half of this loader
	mov cx, 0x1		; One sector
	mov edi, 0x7e00	; Right after this one
	call read_floppy

	; Read in the rest of the disk:
	mov edi, 0x100000	; Destination buffer (at 1 MB) for sector reading in
						; read_floppy
	mov bx, 0x3		; Start at sector 3 (and cylinder 0)
	mov cx, [sectors]	; Read that many sectors
	xor dx, dx			; Start at head 0
	call read_floppy	; Read the remaining sectors at address edi

	; Disable the floppy motor:
	xor al, al
	mov dx, 0x3F2
	out dx, al

	jmp detect_cpu

; These are to make sure the BIOS recognizes this as a bootloader. A
; bootloader needs to be exactly 512 bytes big (first sector) and needs to end
; with the word 0xAA55:
times 510-($-$$) db 0
dw 0xAA55

; Make sure the we have a 486+ CPU (ToriX will be using the invplg instruction
; to invalidate a page, which is first found on the 486):
detect_cpu:
	print detect_cpu_msg

	; =======================================================================
	; === BEGIN SERIES OF INSTRUCTIONS THAT MAGICALLY DETERMINES IF A 486 ===
	; =================== OR HIGHER CPU IS BEING USED. ======================
	; =======================================================================
	pushf
	pushf
	pop ax
	xor ah, ah		; Clear high flags
	push ax
	popf
	pushf
	pop ax
	and ah, 0f0h	; If set, then its not a 486
	jnz .no486

	mov ah, 70h	; Set NT and IOPL flags
	push ax
	popf
	pushf
	pop ax
	and ah, 70h	; If set, then we have a 486
	jz .no486
	popf

	pushfd
	mov eax, [esp]
	or eax, 40000h	; Set AC bit in EFLAGS
	push eax
	popfd
	pushfd
	pop ecx
	xor eax, ecx
	; =======================================================================
	; === END SERIES OF INSTRUCTIONS THAT MAGICALLY DETERMINES IF A 486 =====
	; =================== OR HIGHER CPU IS BEING USED. ======================
	; =======================================================================

	jmp .found
.no486:
	; If a 486+ CPU wasn't found, politely tell them they need one and reboot:
	print	need_486_msg

	; Print a reboot promt and let the user press a key before we reboot:
	print	reboot_msg

	; Wait for a key to be pressed:
	xor ah, ah
	sti			; Enable interrupts
	int 0x16	; Invoke the BIOS => the computer waits for a key
	cli			; Disable interrupts

	; Machine language to jump to FFFF:0000 (reboot):
	db 0EAh
	dw 0000h
	dw 0FFFFh
.found:
	print found_486_msg

	; Reload the GDT:
	lgdt [gdtr]

	; Switch to protected mode, again:
	mov eax, cr0
	or al, 0x1		; Set the protected mode enable bit...
	mov cr0, eax	; ...and write it back.

	jmp dword CODE_SELECTOR:pmode

[bits 32]
pmode:
	; Load the data selector into our stack and segment registers:
	mov eax, DATA_SELECTOR
	mov ss, eax
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax

	; Jump to our C kernel at 0x100000 (1MB):
	jmp dword CODE_SELECTOR:0x100000

; Add more padding to make the entire bootloader 1024 bytes long (two
; sectors):
times 1024-($-$$) db 0
