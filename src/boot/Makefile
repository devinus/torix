boot.bin:
	nasm -f bin boot.asm -o boot.bin

depend:
	@echo \*\*\* No dependencies to generate. Skipping... \*\*\*
	
clean:
	rm -f boot.bin

test:
	dd if=boot.bin seek=0 bs=512 of=../../build/floppy.img conv=notrunc

full:
	$(MAKE) clean
	@echo
	$(MAKE)
	@echo
	$(MAKE) test

dist:
	$(MAKE) clean

install:
	dd if=boot.bin bs=512 of=/dev/fd0