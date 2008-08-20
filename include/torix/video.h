/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#ifndef __VIDEO_H__
#define __VIDEO_H__

void set_attribute(const unsigned short int);
void move_cursor(const unsigned short int, const unsigned short int);
void clear();
void write(const char *);

#endif /* __VIDEO_H__ */
