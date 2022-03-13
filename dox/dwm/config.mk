# dwm/config.mk
# Configuration for the compilation of dwm.
# by decrovert

# Dwm version
VERSION = 6.3-decrovert

# Compiler and linker
CC = gcc

# General paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

# X11
X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama (uncomment if needed)
#XINERAMALIBS = -lXinerama
#XINERAMAFLAGS = -DXINERAMA

# Freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

# OpenBSD (uncomment if needed)
#FREETYPEINC = ${X11INC}/freetype2

# Includes and libs
INCS = -I$(X11INC) -I$(FREETYPEINC)
LIBS = -L$(X11LIB) -lX11 $(XINERAMALIBS) $(FREETYPELIBS)

# Flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L \
	-DVERSION=\"$(VERSION)\" $(XINERAMAFLAGS)

CFLAGS = -std=c17 -w -O2 $(INCS) $(CPPFLAGS)

# Debug mode (uncomment)
#CFLAGS = -std=c17 -pedantic -Wall -Wextra -O0 ${INCS} ${CPPFLAGS}

LDFLAGS = $(LIBS)
