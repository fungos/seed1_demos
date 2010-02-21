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

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
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
