PROJECT=sprite.movie5
include Objects.in
TARGET = ../../../bin/$(PROJECT)

GCC = g++
CFLAGS = -Wall -fPIC -g `sdl-config --cflags` $(CDEFS) -I/media/d/SDK//seed/include -I/media/d/SDK//seeddemos/common/sdl -I..
CDEFS = -D_SDL_ -DDEBUG
LFLAGS = `sdl-config --libs` -lSDL_image -lopenal -lGL -lSeed -logg -lvorbis -lvorbisfile -loggz -loggplay -ltheora
CPPFLAGS = $(CFLAGS)
LIBS = -L/media/d/SDK//seed/bin

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(LFLAGS) $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET) *~
