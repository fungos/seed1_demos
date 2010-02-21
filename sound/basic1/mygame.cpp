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
#if defined(_SDL_)
	u32 mode = static_cast<u32>(Screen::SCREEN_WII);
/*
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
	}*/
#else
#if defined(_WII_)
	UNUSED(argc);
	UNUSED(argv);
#endif
#endif

	pScreen->Setup(VIDEO_MODE);
	pSystem->SetFrameRate(ISystem::RATE_60FPS);
	pSystem->SetApplicationTitle("My awesome game");
	pSystem->SetApplicationDescription("My awesome game save file");
}


BOOL MyGame::Initialize()
{
	this->pRenderer = new Renderer2D();

	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	this->pRenderer->Add(&sptLogo);

/*
	sfxTheme.Load("theme.adpcm", &glMyResources);
	sfxTheme.SetVolume(0.1f);
	sfxTheme.SetLoop(TRUE);
	sfxTheme.Play();
	pSoundSystem->Add(&sfxTheme);
*/

	sfxHelloWorld.Load("sound/basic1/helloworld.sound", &glMyResources);
	pSoundSystem->Add(&sfxHelloWorld);

	sfxPickup.Load("sound/basic1/pickup_item.sound", &glMyResources);
	pSoundSystem->Add(&sfxPickup);

	pSoundSystem->SetSfxVolume(0.5f);
	pSoundSystem->SetMusicVolume(0.5f);

	sfxHelloWorld.Play();
	sfxPickup.SetVolume(0.1f);
	musTheme.Load("sound/basic1/theme.music", &glMyResources);
	musTheme.SetVolume(0.5f);
	musTheme.SetAutoUnload(TRUE);
	pSoundSystem->PlayMusic(&musTheme, 500);
	Log("1");

	return TRUE;
}

static int a = 0;
BOOL MyGame::Update(f32 dt)
{
	a++;
	
	if ((a % 10) == 0) 
		sfxPickup.Play();
	
	if (a == 300)
	{
#if 0
		musTheme2.Load("sound/basic1/theme.music", &glMyResources);
		musTheme2.SetVolume(0.5f);
		musTheme2.SetAutoUnload(TRUE);
		pSoundSystem->PlayMusic(&musTheme2, 500);
#else
		pSoundSystem->StopMusic(500);
#endif
		Log("2");
	}
	else if (a == 600)
	{
		musTheme.Load("sound/basic1/theme.music", &glMyResources);
		musTheme.SetVolume(0.5f);
		musTheme.SetAutoUnload(TRUE);
		pSoundSystem->PlayMusic(&musTheme, 500);
		Log("1");
		a = 0;
	}

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


