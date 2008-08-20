CC     = gcc
CFLAGS = -pipe -march=i386 -m32 -W -Wall -Wextra -ansi -pedantic -ffreestanding -fno-builtin -nostdlib -nostartfiles -nodefaultlibs -Os

OBJS = ctype.o stdlib.o string.o

../../libc/libc.a: $(OBJS)
	ar rcs ../../lib/libc.a $(OBJS)

.c.o:
	$(CC) -I../../include/ $(CFLAGS) -c -o $@ $<

start.o: start.asm
	nasm -f elf $< -o $@

depend:
	sed '/\#\#\# DEPENDENCIES \#\#\#/q' < Makefile > Makefile.tmp
	gcc -M -I../../include *.c >> Makefile.tmp
	mv Makefile.tmp Makefile

clean:
	rm -f $(OBJS)
	rm -f ../../lib/libc.a

install:
	@echo \*\*\* No installation required. Skipping... \*\*\*

full:
	$(MAKE) clean
	@echo
	$(MAKE) depend
	@echo
	$(MAKE)

dist:
	$(MAKE) clean

### DEPENDENCIES ###
ctype.o: ctype.c ../../include/ctype.h
errno.o: errno.c
stdlib.o: stdlib.c ../../include/stdlib.h
string.o: string.c ../../include/string.h
