# dwm version
VERSION = 6.3
VERSION := $(shell git describe --tags)-planet36

# Customize below to fit your system

# paths
PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man

# Xinerama, comment if you don't want it
#XINERAMALIBS  = -lXinerama
#XINERAMAFLAGS = -DXINERAMA

# includes and libs
INCS = `pkg-config --cflags xft`
LIBS = `pkg-config --libs   fontconfig x11 xft` $(XINERAMALIBS)

# flags
CPPFLAGS += -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE $(INCS) $(XINERAMAFLAGS)
DEPFLAGS += -MMD -MP
CFLAGS += -O2 \
		-Wno-shadow \
		-Wno-sign-compare \
		-Wno-unused-parameter
LDLIBS += $(LIBS)

ROFI := $(shell command -v rofi)
ifdef ROFI
	CPPFLAGS += -DUSE_ROFI
endif
undefine ROFI
