#include "mygame.h"
#include "assets.h"


#define BTN_ID_A1	1
#define BTN_ID_A2	2
#define BTN_ID_B1	3
#define BTN_ID_B2	4


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
	strEnabled.Initialize(DIC_ENABLED);
	strDisabled.Initialize(DIC_DISABLED);

	pRenderer = new Renderer2D();

	pSystem->SetLanguage(Seed::en_US);
	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glMyResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	sptLogo.SetPriority(0);
	pRenderer->Add(&sptLogo);

	fntMain.Load(FNT_FONT25, &glMyResources);

	wcAreaA.SetWidth(0.5f);
	wcAreaA.SetHeight(1.0f);
	pGuiManager->Add(&wcAreaA);

	lblTitleA.SetFont(&fntMain);
	lblTitleA.SetText(strEnabled);
	lblTitleA.SetPriority(1);
	wcAreaA.Add(&lblTitleA);
	pRenderer->Add(&lblTitleA);

	// Collision by rect area
	btnBtnA1.Initialize(BTN_ID_A1);
	btnBtnA1.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnBtnA1.SetPriority(1);
	btnBtnA1.SetPosition(0.2f, 0.2f);
	btnBtnA1.SetVisible(TRUE);
	btnBtnA1.AddListener(this);
	wcAreaA.Add(&btnBtnA1);
	pRenderer->Add(&btnBtnA1);

	// Collision by pixel alpha
	btnBtnA2.Initialize(BTN_ID_A2, Seed::CollisionByPixel);
	btnBtnA2.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnBtnA2.SetPriority(1);
	btnBtnA2.SetPosition(0.2f, 0.6f);
	btnBtnA2.SetVisible(TRUE);
	btnBtnA2.AddListener(this);
	wcAreaA.Add(&btnBtnA2);
	pRenderer->Add(&btnBtnA2);


	
	wcAreaB.SetPosition(0.5f, 0.0f);
	wcAreaB.SetWidth(0.5f);
	wcAreaB.SetHeight(1.0f);
	pGuiManager->Add(&wcAreaB);

	lblTitleB.SetFont(&fntMain);
	lblTitleB.SetText(strDisabled);
	lblTitleB.SetPriority(1);
	wcAreaB.Add(&lblTitleB);
	pRenderer->Add(&lblTitleB);

	// Collision by rect area
	btnBtnB1.Initialize(BTN_ID_B1);
	btnBtnB1.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnBtnB1.SetPriority(1);
	btnBtnB1.SetPosition(0.2f, 0.2f);
	btnBtnB1.SetVisible(TRUE);
	btnBtnB1.AddListener(this);
	wcAreaB.Add(&btnBtnB1);
	pRenderer->Add(&btnBtnB1);

	// Collision by pixel alpha
	btnBtnB2.Initialize(BTN_ID_B2, Seed::CollisionByPixel);
	btnBtnB2.SetSprite("gui/basic1/btn_sprite.sprite", &glMyResources);
	btnBtnB2.SetPriority(1);
	btnBtnB2.SetPosition(0.2f, 0.6f);
	btnBtnB2.SetVisible(TRUE);
	btnBtnB2.AddListener(this);
	wcAreaB.Add(&btnBtnB2);
	pRenderer->Add(&btnBtnB2);

	wcAreaB.SetVisible(FALSE);
	wcAreaB.SetDisabled(TRUE);

	return TRUE;
}

static u32 a = 0;
BOOL MyGame::Update(f32 dt)
{
	a++;

	if (a == 300)
	{
		wcAreaA.SetDisabled(TRUE);
		lblTitleA.SetText(strDisabled);

		wcAreaB.SetDisabled(FALSE);
		wcAreaB.SetVisible(TRUE);
		lblTitleB.SetText(strEnabled);
	}
	else if (a == 600)
	{
		wcAreaA.SetDisabled(FALSE);
		lblTitleA.SetText(strEnabled);

		wcAreaB.SetDisabled(TRUE);
		wcAreaB.SetVisible(FALSE);
		lblTitleB.SetText(strDisabled);
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

void MyGame::OnWidgetPress(const EventWidget *ev)
{
	switch (ev->GetSender()->GetId())
	{
		case BTN_ID_A1:
		{
			Log("Button A1 Rect - Pressed!");
		}
		break;

		case BTN_ID_A2:
		{
			Log("Button A2 Pixel - Pressed!");
		}
		break;

		case BTN_ID_B1:
		{
			Log("Button B1 Rect - Pressed!");
		}
		break;

		case BTN_ID_B2:
		{
			Log("Button B2 Pixel - Pressed!");
		}
		break;

		default:
		break;
	}
}
