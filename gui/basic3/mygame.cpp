#include "mygame.h"
#include "assets.h"


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

	pSystem->SetLanguage(Seed::en_US);
	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	sptLogo.SetPriority(0);
	pRenderer->Add(&sptLogo);

	strText.Initialize(DIC_HELLOWORLD);
	strText.Set((WideString)L"%ls", (WideString)L"Seed");

	//fntMain.Load("gui/basic3/font25.font", &glMyResources);
	fntMain.Load(FNT_FONT25, &glMyResources);
	lblMessage.SetFont(&fntMain);
	//lblMessage.SetText((u32)0);
	lblMessage.SetText(strText);
	lblMessage.SetPriority(1);
	pGuiManager->Add(&lblMessage);
	pRenderer->Add(&lblMessage);

	u32 len = 0;
	for (u32 id = 0; id < pDictionary->GetSize(); id++)
	{
		WideString str = pDictionary->GetString(id, &len);
		wprintf(L"%d String: %s Size: %d\n", id, str, len);
	}

/*
	wchar_t buff[1024];
	swprintf(buff, _(2), 111);
	wprintf(L"%s\n", buff);
*/

	pSystem->AddListener(this);

	return TRUE;
}

static int a = 0;
BOOL MyGame::Update(f32 dt)
{
	a++;

	if (a == 200)
	{
		pSystem->SetLanguage(Seed::pt_BR);
	}
	else if (a == 400)
	{
		pSystem->SetLanguage(Seed::en_US);
		a = 0;
	}

	return TRUE;
}

BOOL MyGame::Shutdown()
{
	pSystem->RemoveListener(this);

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

void MyGame::OnSystemLanguageChanged(const EventSystem *ev)
{
	// When language change event happens, you must rebuil your strings.
	strText.Initialize(DIC_HELLOWORLD);
	strText.Set((WideString)L"%ls", (WideString)L"Seed");

	// On language change, we must reload our font so any new characters are loaded.
	fntMain.Load(FNT_FONT25, &glMyResources); 
}
