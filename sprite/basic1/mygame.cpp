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


BOOL MyGame::Initialize()
{
	this->pRenderer = new Renderer2D();

	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	this->pRenderer->Add(&sptLogo);
	pScreen->FadeIn();

	return TRUE;
}


static u32 r = 0;
static BOOL dir = TRUE;
static f32 rot = 0.0f;
static int a = 0;
BOOL MyGame::Update()
{
	sptLogo.SetColor(static_cast<u8>(r), 0, 255, 128);
	//sptHelloWorld.SetScale(0.5f);
	sptLogo.SetBlending(IRenderable::MODULATE);
	sptLogo.SetRotation(rot);

	rot += 0.5f;
	if (dir) r++; else r--;
	if (r == 255) dir = FALSE; else if (r == 0) dir = TRUE;

	if (a == 200) pScreen->FadeOut();
	if (a == 400) { pScreen->FadeIn(); a = 0; }
	a++;

	return TRUE;
}


BOOL MyGame::Shutdown()
{
	glMyResources.Reset();
	delete pRenderer;

	return TRUE;
}


BOOL MyGame::Reset()
{
	return TRUE;
}


