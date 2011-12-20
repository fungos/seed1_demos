#include "mygame.h"

MyGame::MyGame()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	if (cVideo.Load("teste.ogv"))
	{
		//cVideo.PlayToFrame(980);
		iFrames = cVideo.Size();
		//cVideo.GoToFrame(50);
		cVideo.Play();
		//cVideo.SetHeight(1.0f);
		//cVideo.SetWidth(1.0f);
		Log("TOTAL: %d", iFrames);
		//cVideo.GoToFrame(frames / 2);
		cScene.Add(&cVideo);
		pScreen->FadeIn();
	}

	return TRUE;
}

BOOL MyGame::Update(f32 dt)
{
	iCount++;
/*
	if (iCount == 0   ) cVideo.PlayToFrame(30);
	if (iCount == 200 ) cVideo.PlayToFrame(60);
	if (iCount == 400 ) cVideo.PlayToFrame(0);
	if (iCount == 600 ) cVideo.Pause();
	if (iCount == 800 ) cVideo.Play();
	if (iCount == 1000) cVideo.Stop();
	if (iCount == 1200) iCount = 0;
*/
/*
	if (iCount == 0) cVideo.Play();
	if (iCount == 300) cVideo.Stop();
	if (iCount == 600)
	{
		//cVideo.GoToFrame(frames / 2);
		cVideo.Play();
	}

	iCount++;
*/
	cVideo.Update(dt);

	Log(">> %d", cVideo.GetFrameCount());
/*
	if (cVideo.IsPaused())
		Log("Paused!");

	if (cVideo.IsStopped())
		Log("Stopped!");

	if (!cVideo.IsPlaying())
		Log("Not playing!");

	if (cVideo.HasFinished())
	{
		Log("Finished!");
		cVideo.Play();//ToFrame(30);
		iCount = 0;
	}
*/
	return TRUE;
}
