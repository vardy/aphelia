PREFIX?=/usr/X11R6
FLAGS?=-Os -pedantic -Wall

install:
	$(CC) $(CFLAGS) -I$(PREFIX)/include uwurawrxdwm.c -L$(PREFIX)/lib -lX11 -o uwurawrxdwm
	mkdir -p /usr/local/bin
	cp -f uwurawrxdwm /usr/local/bin/

reinstall: clean
	$(CC) $(CFLAGS) -I$(PREFIX)/include uwurawrxdwm.c -L$(PREFIX)/lib -lX11 -o uwurawrxdwm
	mkdir -p /usr/local/bin
	cp -f uwurawrxdwm /usr/local/bin/

clean:
	rm -f uwurawrxdwm
	rm -f /usr/local/lib/uwurawrxdwm
