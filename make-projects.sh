#!/bin/bash

#find | grep -v cpp | grep -v '\.h' | grep -v '\.o' | grep -v project | grep -v '\.git' | grep -v bin | grep -v data | grep -v LICENSE | grep -v Classes | grep -v Basic1 | grep -v '\.mm' | grep -v exporter | grep -v common | grep -v demos.txt | grep -v '.sln' > demos.txt

SEEDSDK=/media/d/SDK/
PROJECTS=`cat demos.txt`
ORIG=`pwd`

for PROJECT in $PROJECTS;
do
	NAME=`echo $PROJECT | cut -c3- | sed 's/\//\./g'`
	cd $PROJECT/project

	echo -en "Building \033[1;32m$NAME\033[0m "

	echo "PROJECT=$NAME" > Makefile
	echo "include Objects.in" >> Makefile 
	echo "TARGET = ../../../bin/\$(PROJECT)" >> Makefile
	echo "" >> Makefile
	echo "GCC = g++" >> Makefile
	echo "CFLAGS = -Wall -fPIC -g \`sdl-config --cflags\` \$(CDEFS) -I$SEEDSDK/seed/include -I$SEEDSDK/seeddemos/common/sdl" >> Makefile
	echo "CDEFS = -D _SDL_ -D _DEBUG_" >> Makefile
	echo "LFLAGS = \`sdl-config --libs\` -L/bin -lSDL_image -lopenal -lGL -lseed -logg -lvorbis -lvorbisfile -loggz -loggplay -ltheora" >> Makefile
	echo "CPPFLAGS = \$(CFLAGS)" >> Makefile
	echo "LIBS = -L$SEEDSDK/seed" >> Makefile
	echo "" >> Makefile
	echo "all:	\$(TARGET)" >> Makefile
	echo "" >> Makefile
	echo "\$(TARGET): \$(OBJECTS)" >> Makefile
	echo "	\$(GCC) -o \$(TARGET) \$(OBJECTS) \$(CPPFLAGS) \$(LFLAGS) \$(LIBS)" >> Makefile
	echo "" >> Makefile
	echo "clean:" >> Makefile
	echo "	rm -f \$(OBJECTS) \$(TARGET) *~" >> Makefile

	make clean &> /dev/null
	 make &> /dev/null
	
	if [ "$?" != "0" ]; then
		echo -e "\033[1;31mFailed!\033[0m"
	else
		echo -e "\033[1;33mOk!\033[0m"
	fi

	cd $ORIG
done;

cd $ORIG
