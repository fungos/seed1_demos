#include "mygame.h"


ResourceManager glMyResources("local");


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

static u32 frames = 0;
BOOL MyGame::Initialize()
{
	pRenderer = new Renderer2D();

	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	cVideo.Load("teste.ogv");
	cVideo.PlayToFrame(980);
	frames = cVideo.Size();
	cVideo.GoToFrame(50);
	Log("TOTAL: %d", frames);
	//cVideo.GoToFrame(frames / 2);
	pRenderer->Add(&cVideo);
	pScreen->FadeIn();

	return TRUE;
}

static int a = 0;
BOOL MyGame::Update(f32 dt)
{
	a++;
/*
	if (a == 0   ) cVideo.PlayToFrame(30);
	if (a == 200 ) cVideo.PlayToFrame(60);
	if (a == 400 ) cVideo.PlayToFrame(0);
	if (a == 600 ) cVideo.Pause();
	if (a == 800 ) cVideo.Play();
	if (a == 1000) cVideo.Stop();
	if (a == 1200) a = 0;
*/
/*
	if (a == 0) cVideo.Play();
	if (a == 300) cVideo.Stop();
	if (a == 600) 
	{
		//cVideo.GoToFrame(frames / 2);
		cVideo.Play();
	}

	a++;
*/
	cVideo.Update();

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
		a = 0;
	}
*/
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
