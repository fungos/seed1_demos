#include "mygame.h"


ResourceManager glMyResources("demo");


MyGame::MyGame()
{
}


MyGame::~MyGame()
{
}


void MyGame::Setup(int argc, char **argv)
{
#ifdef _WII_
	UNUSED(argc);
	UNUSED(argv);
#endif

#ifdef _SDL_
	u32 mode = static_cast<u32>(Screen::SCREEN_WII);

	for (int i = 0; i < argc; i++)
	{
		if (!STRCASECMP(argv[i], "-emulate"))
		{
			if (!STRCASECMP(argv[i+1], "iphone") || !STRCASECMP(argv[i+1], "iph"))
			{
				mode = static_cast<u32>(Screen::SCREEN_IPHONE);
			}
		}


		if (!STRCASECMP(argv[i], "-workdir"))
		{
			pFileSystem->SetWorkDirectory(argv[i+1]);
		}
	}
#endif

	pScreen->Setup(VIDEO_MODE);
	pSystem->SetFrameRate(ISystem::RATE_60FPS);
	pSystem->SetApplicationTitle("My awesome game");
	pSystem->SetApplicationDescription("My awesome game save file");
}


BOOL MyGame::Initialize()
{
	pRenderer = new Renderer2D();

	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	pRenderer->Add(&sptLogo);

	sptArrow.Load("sprite/movie1/arrow.sprite", &glMyResources);
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


BOOL MyGame::Update()
{
	return TRUE;
}


BOOL MyGame::Shutdown()
{
	glMyResources.Reset();
	if (pRenderer)
		delete pRenderer;
	pRenderer = NULL;

	return TRUE;
}


BOOL MyGame::Reset()
{
	return TRUE;
}

