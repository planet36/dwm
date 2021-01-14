# dwm version
VERSION = 6.2
VERSION := $(VERSION)-sdw

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

# Xinerama, comment if you don't want it
#XINERAMALIBS  = -lXinerama
#XINERAMAFLAGS = -DXINERAMA

# includes and libs
INCS = \
       `pkg-config --cflags fontconfig freetype2 x11 xft`
LIBS = $(XINERAMALIBS) \
       `pkg-config --libs fontconfig freetype2 x11 xft`

# flags
CPPFLAGS += -DVERSION=\"$(VERSION)\" -DUSE_ROFI $(XINERAMAFLAGS)
CFLAGS += -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os $(INCS) $(CPPFLAGS)
LDFLAGS += $(LIBS)
