PROJECT=sprite.movie3
include Objects.in
TARGET = ../../../bin/$(PROJECT)

GCC = g++
CFLAGS = -Wall -fPIC -g `sdl-config --cflags` $(CDEFS) -I/media/d/SDK//seed/include -I/media/d/SDK//seeddemos/common/sdl
CDEFS = -D _SDL_ -D _DEBUG_
LFLAGS = `sdl-config --libs` -L/bin -lSDL_image -lopenal -lGL -lseed -logg -lvorbis -lvorbisfile -loggz -loggplay -ltheora
CPPFLAGS = $(CFLAGS)
LIBS = -L/media/d/SDK//seed

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(LFLAGS) $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET) *~
