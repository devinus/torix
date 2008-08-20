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

#ifndef __FLOAT_H__
#define __FLOAT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* The way floating-point numbers are rounded (1 = to nearest). */
#define FLT_ROUNDS		1

/* The base (radix) representation of the exponent. */
#define FLT_RADIX		2

/* The number of digits in the number (in the FLT_RADIX base). */
#define FLT_MANT_DIG	24
#define DBL_MANT_DIG	53
#define LDBL_MANT_DIG	64

/*
 * The maximum number of decimal digits (base-10) that can be represented
 * without change after rounding.
 */
#define FLT_DIG			6
#define DBL_DIG			10
#define LDBL_DIG		10

/* The minimum negative integer value for an exponent in base FLT_RADIX. */
#define FLT_MIN_EXP		(-125)
#define DBL_MIN_EXP		(-1021)
#define LDBL_MIN_EXP	(-16381)

/* The minimum negative integer value for an exponent in base 10. */
#define FLT_MIN_10_EXP	(-37)
#define DBL_MIN_10_EXP	(-307)
#define LDBL_MIN_10_EXP	(-4931)

/* The maximum integer value for an exponent in base FLT_RADIX. */
#define FLT_MAX_EXP		128
#define DBL_MAX_EXP		1024
#define LDBL_MAX_EXP	16384

/* The maximum integer value for an exponent in base 10. */
#define FLT_MAX_10_EXP	38
#define DBL_MAX_10_EXP	308
#define LDBL_MAX_10_EXP	4932

/* Maximum finite floating-point value. */
#define FLT_MAX			3.40282347e+38F
#define DBL_MAX			1.7976931348623157e+308
#define LDBL_MAX		1.7976931348623157e+308L

/* Least significant digit representable. */
#define FLT_EPSILON		1.19209290e-07F
#define DBL_EPSILON		2.2204460492503131e-16
#define LDBL_EPSILON	2.2204460492503131e-16L

/* Minimum floating-point value. */
#define FLT_MIN			1.17549435e-38F
#define DBL_MIN			2.2250738585072014e-308
#define LDBL_MIN		2.2250738585072014e-308L

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __FLOAT_H__ */
