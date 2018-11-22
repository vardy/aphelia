PREFIX?=/usr/X11R6
FLAGS?=-Os -pedantic -Wall

install:
	$(CC) $(CFLAGS) -I$(PREFIX)/include aphelia.c -L$(PREFIX)/lib -lX11 -o aphelia
	mkdir -p /usr/local/bin
	cp -f aphelia /usr/local/bin/

reinstall: clean
	$(CC) $(CFLAGS) -I$(PREFIX)/include aphelia.c -L$(PREFIX)/lib -lX11 -o aphelia
	mkdir -p /usr/local/bin
	cp -f aphelia /usr/local/bin/

clean:
	rm -f aphelia.c
	rm -f /usr/local/lib/aphelia
