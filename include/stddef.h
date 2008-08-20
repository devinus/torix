/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __STDDEF_H__
#define __STDDEF_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define NULL ((void*)0)

typedef unsigned long int ptrdiff_t;
typedef unsigned int size_t;
typedef int wchar_t;

#define offsetof(TYPE, MEMBER) \
	((size_t) &(((TYPE *)0)->MEMBER))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STDDEF_H__ */
