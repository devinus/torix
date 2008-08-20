/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __ASSERT_H__
#define __ASSERT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef NDEBUG
#define assert(e) \
	((e) ? (void)0 :
	printf("Assertion failed: " #e ", file %s, line %d\n", __FILE__,
		__LINE__))
#else /* NDEBUG */
#define assert(ignore) ((void)0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif __ASSERT_H__
