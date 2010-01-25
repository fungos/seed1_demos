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
	pSystem->SetFrameRate(ISystem::RATE_UNLIMITED);
	//pSystem->SetFrameRate(ISystem::RATE_60FPS);
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

	for (u32 i = 0; i < AMOUNT; i++)
	{
		spt[i].Load("sprite/movie1/arrow.sprite", &glMyResources);
		spt[i].SetPriority(i);
		pRenderer->Add(&spt[i]);
		spt[i].SetPosition(pRand->Get(0.0f, 1.0f), pRand->Get(0.0f, 1.0f));
	}

	sptArrow.Load("sprite/movie1/arrow.sprite", &glMyResources);
	sptArrow.SetPriority(1);
	pRenderer->Add(&sptArrow);

	//setup the keyframes
	kf1.bTween		= TRUE;
	kf1.fRotation 	= 0.0f;
	kf1.ptPos.x		= 0.1f;
	kf1.ptPos.y		= 0.7f;

	kf2.bTween		= TRUE;
	kf2.fRotation 	= 0.0f;
	kf2.ptPos.x		= 0.1f;
	kf2.ptPos.y		= 0.1f;

	kf3.bTween		= TRUE;
	kf3.fRotation 	= 90.0f;
	kf3.ptPos.x		= 0.1f;
	kf3.ptPos.y		= 0.1f;

	kf4.bTween		= TRUE;
	kf4.fRotation 	= 90.0f;
	kf4.ptPos.x		= 0.7f;
	kf4.ptPos.y		= 0.1f;

	kf5.bTween		= TRUE;
	kf5.fRotation 	= 180.0f;
	kf5.ptPos.x		= 0.7f;
	kf5.ptPos.y		= 0.1f;

	kf6.bTween		= TRUE;
	kf6.fRotation 	= 180.0f;
	kf6.ptPos.x		= 0.7f;
	kf6.ptPos.y		= 0.7f;

	kf7.bTween		= TRUE;
	kf7.fRotation 	= 270.0f;
	kf7.ptPos.x		= 0.7f;
	kf7.ptPos.y		= 0.7f;

	kf8.bTween		= TRUE;
	kf8.fRotation 	= 270.0f;
	kf8.ptPos.x		= 0.1f;
	kf8.ptPos.y		= 0.7f;

	kf9.bTween		= TRUE;
	kf9.fRotation 	= 360.0f;
	kf9.ptPos.x		= 0.1f;
	kf9.ptPos.y		= 0.7f;

	//setup the timeline
	timeline.AddKeyframe(0, &kf1);
	timeline.AddKeyframe(30, &kf2);
	timeline.AddKeyframe(60, &kf3);
	timeline.AddKeyframe(90, &kf4);
	timeline.AddKeyframe(120, &kf5);
	timeline.AddKeyframe(150, &kf6);
	timeline.AddKeyframe(180, &kf7);
	timeline.AddKeyframe(210, &kf8);

	//these two frames are used so the animation can interpolate correctly back to rotation 0
	//this kind of problem and how to fix it is explained in the next demo
	timeline.AddKeyframe(240, &kf9);
	timeline.AddKeyframe(241, &kf1);
	timeline.SetObject(&sptArrow);

	movie.AddTimeline(&timeline);
	pRenderer->Add(&movie);

	return TRUE;
}

static f32 a = 0;
BOOL MyGame::Update()
{
	for (u32 i = 0; i < AMOUNT; i++)
	{
		spt[i].SetRotation(a);
	}

	a++;
	if (a>=360) a=0;
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


