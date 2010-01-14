#ifndef __MYGAME_H__
#define __MYGAME_H__


#include <Seed.h>

using namespace Seed;

#if defined(_SDL_)
#define VIDEO_MODE	mode
#endif

#if defined(_IPHONE_)
#define VIDEO_MODE Screen::LANDSCAPE
#endif

#if defined(_WII_)
#define VIDEO_MODE	0
#endif


class MyGame : public IGameApp
{
	public:
		MyGame();
		~MyGame();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();
		virtual BOOL Update();
		virtual BOOL Reset();
		virtual BOOL Shutdown();

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Renderer2D *pRenderer;
		Sprite		sptLogo;

		SoundSource sfxHelloWorld;
		SoundSource sfxPickup;
		SoundSource sfxTheme;

		Music		musTheme;
		Music		musTheme2;
};


#endif // __MYGAME_H__
