/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __STRING_H__
#define __STRING_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define NULL ((void*)0)

typedef unsigned int size_t;

void *memchr(const void *, int, size_t);
void *memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
char *strcat(char *, const char *);
size_t strlen(const char *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STRING_H__ */
