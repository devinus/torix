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

#ifndef __LIMITS_H__
#define __LIMITS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Number of bits in a char. */
#define CHAR_BIT	8

/* Minimum and maximum values a signed char can hold. */
#define SCHAR_MIN	(-127)
#define SCHAR_MAX	127

/* Maximum value a unsigned char can hold. */
#define UCHAR_MAX	255

/*
 * Minimum and maximum value a char can hold. If a char is being represented
 * as a signed integer, then their values are the same as the signed char
 * values. Otherwise CHAR_MIN is 0 and CHAR_MAX is the same as UCHAR_MAX.
 */
# define CHAR_MIN	SCHAR_MIN
# define CHAR_MAX	SCHAR_MAX

/* Maximum number of bytes in a multibyte character. */
#define MB_LEN_MAX	1

/* Minimum and maximum values a short int can hold. */
#define SHRT_MIN	(-32767)
#define SHRT_MAX	32767

/* Maximum value an unsigned short int can hold. */
#define USHRT_MAX	65535

/* Minimum and maximum values an int can hold. */
#define INT_MIN		(-32767)
#define INT_MAX		32767

/* Maximum value an unsigned int can hold. */
#define UINT_MAX	65535

/* Minimum and maximum value a long int can hold. */
#define LONG_MIN	(-2147483647)
#define LONG_MAX	2147483647

/* Maximum value an unsigned long int can hold. */
#define ULONG_MAX	4294967295
#define ULONG_MAX	4294967295

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LIMITS_H__ */
