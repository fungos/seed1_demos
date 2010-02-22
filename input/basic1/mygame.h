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

		// IEventInputKeyboardListener
		virtual void OnInputKeyboardPress(const EventInputKeyboard *ev);
		virtual void OnInputKeyboardRelease(const EventInputKeyboard *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Label		lblMessage;
		Font		fntMain;
		String		strText;

		BOOL		bToggle;
};

#endif // __MYGAME_H__
