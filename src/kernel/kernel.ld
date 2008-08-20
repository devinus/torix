OUTPUT_FORMAT("binary")
OUTPUT_ARCH(i386)
ENTRY(start)
KERNEL_OFFSET = 0x100000;
SECTIONS
{
	. = KERNEL_OFFSET;

	.text :
	{
		*(.text)
		*(.rodata)
		. = ALIGN(4096);
	}
	.data :
	{
		*(.data)
		. = ALIGN(4096);
	}
	.bss :
	{
		*(.bss)
		*(COMMON)
		. = ALIGN(4096);
	}

	end = .;
}
