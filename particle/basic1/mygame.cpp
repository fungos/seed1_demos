#include "mygame.h"


const char *table[] = {
	"particle/basic1/particle1.psi",
	"particle/basic1/particle2.psi",
	"particle/basic1/particle3.psi",
	"particle/basic1/particle4.psi",
	"particle/basic1/particle5.psi",
	"particle/basic1/particle6.psi",
	"particle/basic1/particle7.psi",
	"particle/basic1/particle8.psi",
	"particle/basic1/particle9.psi"
};

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

	pScreen->Setup(VIDEO_MODE);

	pScreen->Setup(Screen::SCREEN_800X600X32W_OPENGL);
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
	pRenderer->Add(&sptLogo);

	cEmitter.Load(table[0], &glMyResources);
	cEmitter.SetSprite("particle/basic1/particle.sprite");
	cEmitter.SetPriority(10);
	cEmitter.SetPosition(0.5f, 0.5f);
	cEmitter.Play();
	pRenderer->Add(&cEmitter);
	pParticleManager->Add(&cEmitter);
	pInput->AddKeyboardListener(this);

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

void MyGame::OnInputKeyboardRelease(const EventInputKeyboard *ev)
{
	Key k = ev->GetKey();

	if (k.IsNumber())
	{
		u32 v = k.GetValue() - '1';
		if (v >= 0 && v < 9)
		{
			cEmitter.Unload();
			cEmitter.Load(table[v], &glMyResources);
			cEmitter.SetSprite("particle/basic1/particle.sprite");
		}
	}
	else
	{
		u32 v = k.GetValue() - static_cast<u32>(Seed::KeyF1);
		if (v >= 0 && v < 15)
			cEmitter.SetAnimation(v);
	}
}

