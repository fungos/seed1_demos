@echo Building SDL demo files
rem del cache.sdl.txt
del StringCache.txt
sexport -i sdl.xml -p sdl -v
copy sdl.h %TF_BASE%\SDK\demos\common\sdl\assets.h
@echo Building WII demo files
rem del cache.wii.txt
rem del StringCache.txt
rem sexport -i wii.xml -p wii -v
rem copy wii.h %TF_BASE%\SDK\demos\common\wii\assets.h
@echo Done!
pause