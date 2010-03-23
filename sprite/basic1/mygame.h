#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

class MyGame : public DemoBase
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Update(f32 dt);
		
	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		//u8 buff[7658];
		//u8 buff[288];
		u8 buff[2557];
		Sprite spt;
		Sprite x[100];
		//Sprite spt[8];
		//f32 fRot;
		//u32 iCol;
		//u32 iCount;
		//BOOL bDir;
};

#endif // __MYGAME_H__
