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
