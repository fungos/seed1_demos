#include "mygame.h"


ResourceManager glMyResources("mine");


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

	pScreen->Setup(Screen::SCREEN_WII); //VIDEO_MODE);
	pSystem->SetFrameRate(ISystem::RATE_60FPS);
	pSystem->SetApplicationTitle("My awesome game");
	pSystem->SetApplicationDescription("My awesome game save file");
}

BOOL MyGame::Initialize()
{
	pRenderer = new Renderer2D();

	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptBg1.Load("sprite/advanced1/layer1.sprite", &glMyResources);
	sptBg1.SetPosition(0.0f, 0.0f);
	sptBg1.SetVisible(TRUE);
	pRenderer->Add(&sptBg1);

	sptBg2.Load("sprite/advanced1/layer2.sprite", &glMyResources);
	sptBg2.SetPosition(0.0f, 0.0f);
	sptBg2.SetVisible(TRUE);
	sptBg2.SetMasked(TRUE);
	pRenderer->Add(&sptBg2);

	sptGlassMask.Load("sprite/advanced1/glass_mask.sprite", &glMyResources);
	sptGlassMask.SetVisible(TRUE);
	sptGlassMask.SetMask(TRUE);
	pRenderer->Add(&sptGlassMask);

	sptGlass.Load("sprite/advanced1/glass.sprite", &glMyResources);
	sptGlass.SetVisible(TRUE);
	sptGlass.SetSpecial(TRUE);
	sptGlass.SetPriority(10);
	pRenderer->Add(&sptGlass);

	pInput->AddPointerListener(this);

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

void MyGame::OnInputPointerMove(const EventInputPointer *ev)
{
	sptGlassMask.SetPosition(ev->GetX(), ev->GetY());
	sptGlass.SetPosition(ev->GetX(), ev->GetY());
}
