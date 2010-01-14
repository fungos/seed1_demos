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
		Sprite		sptArrow;

		Movie		movie;

		Timeline	timeline;
		Keyframe	kf1;
		Keyframe	kf2;
		Keyframe	kf3;
		Keyframe	kf4;
		Keyframe	kf5;
		Keyframe	kf6;
		Keyframe	kf7;
		Keyframe	kf8;
		Keyframe	kf9;
};


#endif // __MYGAME_H__
