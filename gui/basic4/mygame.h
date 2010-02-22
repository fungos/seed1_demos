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
		virtual BOOL Update(f32 dt);

		// IEventWidgetListener
		virtual void OnWidgetPress(const EventWidget *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Label		lblTitleA;
		Button		btnBtnA1;
		Button		btnBtnA2;
		WidgetContainer wcAreaA;

		Label		lblTitleB;
		Button		btnBtnB1;
		Button		btnBtnB2;
		WidgetContainer wcAreaB;

		String		strEnabled;
		String		strDisabled;
		
		Font		fntMain;
		u32		iCount;
};

#endif // __MYGAME_H__
