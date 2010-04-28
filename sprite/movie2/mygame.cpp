#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	sptArrow.Load(SPT_ARROW, &glDemoResources);
	sptArrow.SetPriority(1);
	pRenderer->Add(&sptArrow);

	//setup the keyframes
	kf1.bTween		= TRUE;
	kf1.fRotation 	= 0.0f;

	kf2.bTween		= TRUE;
	kf2.fRotation 	= 360.0f;

	//NOTE: Rotation 0 == rotation 360 so frame 120 and 121 (which in the timeline is the frame 0 again)
	//actually have the same info, this causes the effect of a "lockup" in the animation because
	//during two frames the animation stood still
	//This often happens in looped animations that involve complex rotations, and below is a way to fix
	//it: when the animation ends, tell it to jump to frame 1 instead of frame 0, so the animation
	//will run smoothly.
	//If you want to see the lockup, simply comment the two lines below.
	kf2.iEvent = Keyframe::KEYFRAME_EVENT_JUMPTOFRAME;
	kf2.iFrameToJump= 1;

	//setup the timeline
	timeline.AddKeyframe(0, &kf1);
	timeline.AddKeyframe(120, &kf2);
	timeline.SetObject(&sptArrow);

	movie.AddTimeline(&timeline);
	movie.SetPosition(0.42f, 0.20f);
	movie.SetLocalPosition(0.0f, 0.2f);
	pRenderer->Add(&movie);

	return TRUE;
}
