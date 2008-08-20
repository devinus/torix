/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
	const char *tmp = (const char *)s;

	while (n) {
		if (*tmp == c) {
			return (void *)tmp;
		}

		++tmp;
		--n;
	}

	return NULL;
}

void *memcmp(const void *s1, const void *s2, size_t n)
{
	const char *tmp1 = (const char *)s1;
	const char *tmp2 = (const char *)s2;

	while (n) {
		if (*tmp1++ != *tmp2++) {
			return (void *)(*--tmp1 - *--tmp2);
		}

		--n;
	}

	return NULL;
}

void *memcpy(void *s1, const void* s2, size_t n)
{
	char *tmp1 = (char *)s1;
	const char *tmp2 = (const char *)s2;

	while (n) {
		*tmp1 = *tmp2;

		++tmp1;
		++tmp2;
		--n;
	}

	return s1;
}

void *memmove(void *s1, const void *s2, size_t n)
{
	char *tmp1 = s1;
	const char *tmp2 = s2;

	if (tmp2 < tmp1 && tmp1 < (tmp2 + n)) {
		tmp1 += n;
		tmp2 += n;

		while (n) {
			--tmp1;
			--tmp2;

			*tmp1 = *tmp2;

			--n;
		}
	} else {
		while (n) {
			*tmp1 = *tmp2;

			++tmp1;
			++tmp2;
			--n;
		}
    }

  return s1;
}

void *memset(void *s, int c, size_t n)
{
	char *tmp = s;

	while (n) {
		*tmp = c;
		++tmp;
		--n;
	}

	return s;
}

char *strcat(char *s1, const char *s2)
{
	while (*s1) {
		++s1;
	}

	while ((*s1++ = *s2++)) {
		/* Do nothing */ ;
	}

	return s1;
}

size_t strlen(const char *s)
{
	size_t len = 0;

	while (s[len]) {
		++len;
	}

	return len;
}
