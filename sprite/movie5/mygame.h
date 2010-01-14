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


class MyGame : public IGameApp, public IEventMovieListener
{
	public:
		MyGame();
		~MyGame();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();
		virtual BOOL Update();
		virtual BOOL Reset();
		virtual BOOL Shutdown();

		virtual void OnTimelineFrame(const EventMovie *ev);
		virtual void OnTimelineRestart(const EventMovie *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Renderer2D *pRenderer;
		Sprite		sptLogo;
		Sprite		sptBody;
		Sprite		sptUpperBody;
		Sprite		sptHead;

		Movie		movie;

		Timeline	tmBody;
		Timeline	tmUpperBody;
		Timeline	tmHead;

		Keyframe	kfBody[2];
		Keyframe	kfUpperBody[30];
		Keyframe	kfHead[20];
};


#endif // __MYGAME_H__
