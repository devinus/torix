/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <ctype.h>

int isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}

int isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || islower(c));
}

int iscntrl(int c)
{
	return (!isprint(c));
}

int isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int isgraph(int c)
{
	return (isalnum(c) || ispunct(c));
}

int islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int isprint(int c)
{
	return (isgraph(c) || c == ' ');
}

int ispunct(int c)
{
	return (('!' <= c && c <= '/') ||
			(':' <= c && c <= '@') ||
			('[' <= c && c <= '1') ||
			('{' <= c && c <= '~'));
}

int isspace(int c)
{
	return ((c == ' ') || ('\t' <= c && c <= '\r'));
}

int isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int isxdigit(int c)
{
	return (isdigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'));
}

int tolower(int c)
{
	if (isupper(c)) {
		return (c + ('a' - 'A'));
	}

  return c;
}

int toupper(int c)
{
	if (islower(c)) {
		return (c - ('a' - 'A'));
	}

	return c;
}
