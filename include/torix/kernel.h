/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __KERNEL_H__
#define __KERNEL_H__

void outportb(const unsigned int, const unsigned char);
void outportw(const unsigned int, const unsigned int);
unsigned char inportb(const unsigned short int);

#endif /* __KERNEL_H__ */
