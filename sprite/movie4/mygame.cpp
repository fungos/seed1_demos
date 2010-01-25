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

	spt.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	spt.SetPriority(0);
	spt.SetBlending(IRenderable::MODULATE);
	pRenderer->Add(&spt);

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
	timeline.SetObject(&spt);

	movie.AddTimeline(&timeline);
	movie.SetLocalPosition(0.0f, 0.5f); //changes the local position for all keyframes
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


