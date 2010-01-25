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
	sptLogo.SetPriority(0);
	pRenderer->Add(&sptLogo);

	sptSpotlight.Load("sprite/movie3/spotlight.sprite", &glMyResources);
	sptSpotlight.SetPriority(1);
	pRenderer->Add(&sptSpotlight);
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


