PROJECT=video.basic1
include Objects.in
TARGET = ../../../bin/$(PROJECT)

GCC = g++
CFLAGS = -Wall -fPIC -g `sdl-config --cflags` $(CDEFS) -I$(SEEDSDK)/seed/include -I$(SEEDSDK)/seeddemos/common/sdl -I..
CDEFS = -D_SDL_ -DDEBUG
LIBS = -lSDL_image -lopenal -lGL -lSeed -logg -lvorbis -lvorbisfile -loggz -loggplay -ltheora
CPPFLAGS = $(CFLAGS)
LFLAGS = `sdl-config --libs` -L$(SEEDSDK)/seed/bin

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(LFLAGS) $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET) *~
