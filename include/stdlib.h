/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __STDLIB_H__
#define __STDLIB_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define NULL ((void*)0)

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX 2147483647

#define MB_CUR_MAX 2

typedef unsigned int size_t;
typedef int wchar_t;

typedef struct {
	int quot;
	int rem;
}
div_t;

typedef struct {
	long quot;
	long rem;
}
ldiv_t;

int abs(int);
div_t div(int, int);
long int labs(long int);
ldiv_t ldiv(long int, long int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STDLIB_H__ */
