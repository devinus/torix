/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <torix/kernel.h>

__inline__ void outb(const unsigned int port, const unsigned char value)
{
	__asm__ __volatile__ ("outb %%al,%%dx": :"d" (port), "a" (value));
}

__inline__ void outw(const unsigned int port, const unsigned int value)
{
	__asm__ __volatile__ ("outw %%ax,%%dx": :"d" (port), "a" (value));
}

__inline__ unsigned char inb(const unsigned short int port)
{
	unsigned char ret_val;

	__asm__ __volatile__ ("inb %w1,%b0" : "=a"(ret_val) : "d"(port));

	return ret_val;
}
