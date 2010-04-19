#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

class MyGame : public DemoBase, public IEventMovieListener
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Initialize();

		virtual void OnTimelineFrame(const EventMovie *ev);
		virtual void OnTimelineRestart(const EventMovie *ev);

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
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

		Teste		teste;
		Image		img;
};


#endif // __MYGAME_H__
