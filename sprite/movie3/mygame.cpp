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

	sptSpotlight.Load(SPT_SPOTLIGHT);
	sptSpotlight.SetPriority(1);
	timeline.SetObject(&sptSpotlight);

	//setup the keyframes
	BOOL tween		= TRUE; //SET TO FALSE TO SEE WHAT HAPPENS

	kf1.bTween		= tween;
	kf1.fRotation 	= 20.0f;
	kf1.fEasing		= -1.0f;

	kf2.bTween		= tween;
	kf2.fRotation 	= 0.0f;
	kf2.fEasing		= 1.0f;

	kf3.bTween		= tween;
	kf3.fRotation 	= -20.0f;
	kf3.fEasing		= -1.0f;

	kf4.bTween		= tween;
	kf4.fRotation 	= 0.0f;
	kf4.fEasing		= 1.0f;

	kf5.bTween		= tween;
	kf5.fRotation 	= 20.0f;
	kf5.fEasing		= 1.0f;

	//setup the timeline
	timeline.AddKeyframe(0, &kf1);
	timeline.AddKeyframe(30, &kf2);
	timeline.AddKeyframe(60, &kf3);
	timeline.AddKeyframe(90, &kf4);
	timeline.AddKeyframe(120, &kf5);

	movie.AddTimeline(&timeline);
	movie.SetPosition(0.43f, 0.30f);
	movie.SetLocalPosition(0.0f, -0.3f);
	movie.SetPriority(1);
	cScene.Add(&movie);
	
	return TRUE;
}
