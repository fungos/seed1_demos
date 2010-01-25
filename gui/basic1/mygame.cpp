#include "mygame.h"


#define BTN_ID1		1
#define BTN_ID2		2


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

	// Collision by rect area
	btnRect.Initialize(BTN_ID1);
	btnRect.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnRect.SetPriority(1);
	btnRect.SetPosition(0.28f, 0.4f);
	btnRect.SetVisible(TRUE);
	btnRect.AddListener(this);
	pRenderer->Add(&btnRect);
	pGuiManager->Add(&btnRect);

	// Collision by pixel alpha
	btnPixel.Initialize(BTN_ID2, Seed::CollisionByPixel);
	btnPixel.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnPixel.SetPriority(1);
	btnPixel.SetPosition(0.62f, 0.4f);
	btnPixel.SetVisible(TRUE);
	btnPixel.AddListener(this);
	pRenderer->Add(&btnPixel);
	pGuiManager->Add(&btnPixel);

	return TRUE;
}


void MyGame::OnWidgetPress(const EventWidget *ev)
{
	switch (ev->GetSender()->GetId())
	{
		case BTN_ID1:
		{
			Log("Button 1 Rect - Pressed!");
		}
		break;

		case BTN_ID2:
		{
			Log("Button 2 Pixel - Pressed!");
		}
		break;

		default:
		break;
	}
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


