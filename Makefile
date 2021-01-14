# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRCS = drw.c dwm.c util.c
OBJS = $(SRCS:.c=.o)

all: options dwm

options:
	@echo dwm build options:
	@echo "CFLAGS  = $(CFLAGS)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "CC      = $(CC)"

config.h:
	cp config.def.h config.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(OBJS): config.h config.mk

dwm: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -f dwm *.o dwm-$(VERSION).tar.gz

dist: clean
	git archive --prefix dwm-$(VERSION)/ HEAD | gzip > dwm-$(VERSION).tar.gz

install: dwm
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f dwm $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dwm
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < dwm.1 > $(DESTDIR)$(MANPREFIX)/man1/dwm.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/dwm.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm\
		$(DESTDIR)$(MANPREFIX)/man1/dwm.1

.PHONY: all options clean dist install uninstall
