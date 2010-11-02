@echo Building SDL demo files
cd %SEEDSDK%\seeddemos\exporter
del cache.sdl.txt
del StringCache.txt
sexport -i seeddemos.xml -p sdl
copy seeddemos.h "%SEEDSDK%\seeddemos\common\sdl\assets.h"
@echo Done!
pause