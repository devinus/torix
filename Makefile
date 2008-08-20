VERSION = 0.0.1

DIRS =	src/boot/	\
	src/libc	\
	src/kernel/

all:
	@echo Building ToriX OS...
	@echo --------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir; \
	done

depend:
	@echo Generating dependencies...
	@echo --------------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir depend; \
	done

clean:
	@echo Removing old or unessecary files...
	@echo -----------------------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir clean; \
	done

install:
	@echo Installing onto a floppy...
	@echo ---------------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir install; \
	done

full:
	@echo Fully cleaning, compiling, and installing...
	@echo --------------------------------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir full; \
	done

dist:
	@echo Creating a distribution...
	@echo --------------------------
	for dir in $(DIRS); \
		do $(MAKE) -C $$dir dist; \
	done
	@echo
	(cd ..; tar cv torix | gzip > torix-$(VERSION).tar.gz; cd torix)
