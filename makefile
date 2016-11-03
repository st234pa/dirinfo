GCC = gcc -g

all: dirinfo.c
	$(GCC) dirinfo.c -o dirinfo

dirinfo.c: dirinfo.c
	$(GCC) -c dirinfo.c

clean:
	rm *.o
	rm *~

run: all
	./dirinfo

debug: all
	gdb dirinfo
