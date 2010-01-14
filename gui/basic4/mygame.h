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

class MyGame : public IGameApp, public IEventWidgetListener
{
	public:
		MyGame();
		~MyGame();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();
		virtual BOOL Update();
		virtual BOOL Reset();
		virtual BOOL Shutdown();

		virtual void OnWidgetPress(const EventWidget *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Renderer2D		*pRenderer;
		Sprite			sptLogo;

		Label			lblTitleA;
		Button			btnBtnA1;
		Button			btnBtnA2;
		WidgetContainer wcAreaA;

		Label			lblTitleB;
		Button			btnBtnB1;
		Button			btnBtnB2;
		WidgetContainer wcAreaB;

		String			strEnabled;
		String			strDisabled;
		
		Font			fntMain;
};


#endif // __MYGAME_H__
