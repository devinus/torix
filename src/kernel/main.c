/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <torix/kernel.h>
#include <torix/video.h>
#include <stdlib.h>

int main()
{
	set_attribute(0x0400);
	write("\nT");
	set_attribute(0x0700);
	write("ori");
	set_attribute(0x0100);
	write("X\n");
	set_attribute(0x0700);
	write("Version 0.0.1\n\nSuccess!\n\nEntering sleep...\n\n");

	while (1);

	return 0;
}
