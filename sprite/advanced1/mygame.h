#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

class MyGame : public DemoBase, public IEventInputPointerListener
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Initialize();
		virtual void OnInputPointerMove(const EventInputPointer *ev);
		
	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Sprite		sptBg1;
		Sprite		sptBg2;
		Sprite		sptGlass;
		Sprite		sptGlassMask;
};


#endif // __MYGAME_H__
