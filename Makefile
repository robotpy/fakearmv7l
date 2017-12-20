
.PHONY: all clean install

all: libfakearmv7l.so ;

fakearm.o: fakearm.c
	gcc -Wall -fPIC -g -c -DLINUX -Wall fakearm.c

libfakearmv7l.so: fakearm.o
	gcc -shared -rdynamic -Wl,-soname,libfakearmv7l.so -o libfakearmv7l.so fakearm.o -ldl

clean:
	rm fakearm.o libfakearmv7l.so
	
install:
	cp libfakearmv7l.so /usr/local/lib/libfakearmv7l.so
