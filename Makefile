# Makefile for caanoo
#

CAANOODEV = /usr/local/GPH_SDK
SDL_CONFIG = $(CAANOODEV)/bin/sdl-config

CC=$(CAANOODEV)/tools/gcc-4.2.4-glibc-2.7-eabi/bin/arm-gph-linux-gnueabi-gcc
CXX=$(CAANOODEV)/tools/gcc-4.2.4-glibc-2.7-eabi/bin/arm-gph-linux-gnueabi-g++
STRIP=$(CAANOODEV)/tools/gcc-4.2.4-glibc-2.7-eabi/bin/arm-gph-linux-gnueabi-strip

CFLAGS  = $(shell $(SDL_CONFIG) --cflags) -g  -I$(CAANOODEV)/include -c -DCAANOO -D_DEBUG
LDFLAGS =  -L$(CAANOODEV)/lib -lSDL_image -lSDL -lSDL_ttf -lSDL_mixer \
$(CAANOODEV)/tools/gcc-4.2.4-glibc-2.7-eabi/arm-gph-linux-gnueabi/lib/libstdc++.a \
$(CAANOODEV)/tools/gcc-4.2.4-glibc-2.7-eabi/arm-gph-linux-gnueabi/sys-root/usr/lib/libpng.a \
-lz -lm -lpthread

SOURCES=main.c draw.c level.c link.c init.c enemy.c event.c menu.c music.c game.c skeleton.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Zelda.gpe
FILES=$(.c~=.h~=.o)

ALL_CFLAGS = $(STDC_HDRS) $(UTIME_H) $(UTIME_NULL) $(UTIMBUF) $(CFLAGS)

all: $(SOURCES) $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS)
	$(CC) -D_DEBUG  $(LDFLAGS) $(OBJECTS) -o $@
#	$(STRIP) $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o

