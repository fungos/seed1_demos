#ifndef __MYGAME_H__
#define __MYGAME_H__


#include <Seed.h>

using namespace Seed;

#ifdef _SDL_
#define VIDEO_MODE	mode
#endif

#ifdef _IPHONE_
#define VIDEO_MODE Screen::LANDSCAPE
#endif

#ifdef _WII_
#define VIDEO_MODE
#endif

class MyGame : public IGameApp, public IEventInputKeyboardListener
{
	public:
		MyGame();
		~MyGame();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();
		virtual BOOL Update();
		virtual BOOL Reset();
		virtual BOOL Shutdown();

		// IEventInputKeyboardListener
		virtual void OnInputKeyboardPress(const EventInputKeyboard *ev);
		virtual void OnInputKeyboardRelease(const EventInputKeyboard *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Renderer2D *pRenderer;
		Sprite		sptLogo;
		Label		lblMessage;
		Font		fntMain;
		String		strText;
};


#endif // __MYGAME_H__