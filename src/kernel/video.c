/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <torix/kernel.h>
#include <torix/video.h>
#include <string.h>

static unsigned short int *videomem = (unsigned short *)0xB8000;
static unsigned short int attrib = 0x0700;
static unsigned short int pos = 0;
static unsigned short int off = 160;

void set_attribute(const unsigned short int att)
{
	attrib = att;
}

void move_cursor(const unsigned short int row, const unsigned short int col)
{
	unsigned short int position = (row * 80) + col;

	outb(0x3D4, 0x0F);
	outb(0x3D5, position & 0xFF);
	outb(0x3D4, 0x0E);
	outb(0x3D5, (position >> 8) & 0xFF);
}

void clear()
{
	unsigned short int i = 0;

	while (i < 2000) {
		videomem[i] = ' ' | attrib;
		++i;
	}

	pos = off = 0;

	move_cursor(0, 0);
}

void write(const char* msg)
{
	unsigned short int len = strlen(msg);

	while (*msg) {
		/*
		 * If the number of characters on the current line goes over 80
		 * characters, then wrap around the screen.
		 */
		if (pos >= 80) {
			pos = 0;
			off += 80;
		}

		/*
		 * If the text goes beyond 25 lines, then copy the first 24 lines one
		 * line up, and finally fill the 25th line with spaces to clear it for
		 * something else to be written over.
		 */
		if (off >= 2000) {
			unsigned short int i = 0;

			while (i < 1920) {
				videomem[i] = videomem[i + 80];
				++i;
			}

			while (i < 2000) {
				videomem[i] = ' ' | attrib;
				++i;
			}

			pos = 0;
			off = (80 * 24);
    	}

    	switch (*msg) {
    	case '\n':
			pos = 0;
			off += 80;
			++msg;
			len = strlen(msg);

			break;
		case '\t':
			write("    ");

			len += 7;
			++msg;

			break;
		default:
			videomem[off + pos] = *msg | attrib;
			++pos;
			++msg;
		}
	}

	move_cursor(off / 80, len);
}
