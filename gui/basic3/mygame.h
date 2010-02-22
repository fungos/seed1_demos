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

		virtual void OnSystemLanguageChanged(const EventSystem *ev);
		
	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Label		lblMessage;
		Font		fntMain;
		String		strText;
		u32		iCount;
};


#endif // __MYGAME_H__
