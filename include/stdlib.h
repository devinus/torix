/*
 * ToriX - TORres Interactive eXecution
 * Copyright (C) 2007  Devin Torres
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
