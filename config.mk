# dwm version
VERSION = 6.8

VERSION := $(shell git describe --tags --abbrev=0)-planet36

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
CPPFLAGS = -MMD -MP
CPPFLAGS += -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE $(INCS) $(XINERAMAFLAGS)

CFLAGS = -std=c23
CFLAGS += -pipe -Wall -Wextra -Wpedantic -Wfatal-errors
CFLAGS += -O3 -flto=auto -march=native
CFLAGS += -Wno-shadow
CFLAGS += -Wno-sign-compare
CFLAGS += -Wno-unused-parameter

LDLIBS = $(LIBS)
