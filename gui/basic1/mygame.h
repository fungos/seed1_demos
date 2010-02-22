#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

class MyGame : public DemoBase, public IEventWidgetListener
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Initialize();

		// IEventWidgetListener
		virtual void OnWidgetPress(const EventWidget *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Button		btnRect;
		Button		btnPixel;
};

#endif // __MYGAME_H__
