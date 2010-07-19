#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

class MyGame : public DemoBase
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Initialize();
		virtual BOOL Update(f32 dt);
		
	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Theora		cVideo;
		u32 		iFrames;
		u32			iCount;
};

#endif // __MYGAME_H__
