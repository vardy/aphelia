PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include uwurawrxdwm.c -L$(PREFIX)/lib -lX11 -o uwurawrxdwm

clean:
	rm -f  uwurawrxdwm

