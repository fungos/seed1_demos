#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

#define AMOUNT 1024

class MyGame : public DemoBase
{
	public:
		MyGame();
		~MyGame();

		virtual BOOL Initialize();
		virtual BOOL Update(f32 dt);
		
	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Sprite		sptArrow;
		Sprite		spt[AMOUNT];

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

		f32		fAngle;
};


#endif // __MYGAME_H__
