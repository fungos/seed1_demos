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

	//setup the keyframes
	kf1.bTween		= TRUE;
	kf1.fRotation 	= -60.0f;
	kf1.ptScale.x	= 0.5f;
	kf1.ptScale.y	= 0.5f;
	kf1.fEasing		= -1.0f;
	kf1.iColorG		= 0;

	kf2.bTween		= TRUE;
	kf2.fRotation 	= 0.0f;
	kf2.fEasing		= 1.0f;
	kf2.iColorG		= 255;
	kf2.iColorR		= 255;

	kf3.bTween		= TRUE;
	kf3.fRotation 	= 60.0f;
	kf3.ptScale.x	= 0.5f;
	kf3.ptScale.y	= 0.5f;
	kf3.fEasing		= 1.0f;
	kf3.iColorR		= 0;

	//setup the timeline
	timeline.AddKeyframe(0, &kf1);
	timeline.AddKeyframe(60, &kf2);
	timeline.AddKeyframe(120, &kf3);
	timeline.AddKeyframe(180, &kf2);
	timeline.AddKeyframe(240, &kf1);
	timeline.SetObject(&sptLogo);

	movie.AddTimeline(&timeline);
	movie.SetLocalPosition(0.0f, 0.5f); //changes the local position for all keyframes
	cScene.Add(&movie);

	return TRUE;
}
