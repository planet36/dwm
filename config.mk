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
INCS = `pkg-config --cflags fontconfig freetype2 x11 xft`
LIBS = `pkg-config --libs   fontconfig freetype2 x11 xft` $(XINERAMALIBS)

# flags
CPPFLAGS += -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -DUSE_ROFI $(XINERAMAFLAGS)
DEPFLAGS += -MMD -MP
CFLAGS += -Os \
		-Wno-deprecated-declarations \
		-Wno-shadow \
		-Wno-sign-compare \
		-Wno-unused-parameter
CFLAGS += $(INCS) $(CPPFLAGS) $(DEPFLAGS)
LDFLAGS += $(LIBS)
