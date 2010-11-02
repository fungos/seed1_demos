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
		Sprite spt;
		f32 fRot;
		u32 iCol;
		u32 iCount;
		BOOL bDir;
};

#endif // __MYGAME_H__
