#include "mygame.h"
#include "assets.h"


ResourceManager glMyResources("demo");


MyGame::MyGame()
{
}

MyGame::~MyGame()
{
	pInput->RemoveKeyboardListener(this);
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

	fntMain.Load(FNT_FONT25, &glMyResources);
	lblMessage.SetFont(&fntMain);
	lblMessage.SetPriority(1);
	lblMessage.SetPosition(0.0f, 0.55f);
	lblMessage.SetWidth(1.0f);
	lblMessage.SetAlignment(HorizontalAlignCenter);
	pGuiManager->Add(&lblMessage);
	pRenderer->Add(&lblMessage);

	pInput->AddKeyboardListener(this);

	Log("Is Motion: %s", pInput->IsMotion() ? "Yes" : "No");
	Log("Is Pointer: %s", pInput->IsPointer() ? "Yes" : "No");
	Log("Is Joystick: %s", pInput->IsJoystick() ? "Yes" : "No");
	Log("Is Keyboard: %s", pInput->IsKeyboard() ? "Yes" : "No");

	return TRUE;
}

BOOL MyGame::Update(f32 dt)
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

BOOL b = FALSE;
void MyGame::OnInputKeyboardPress(const EventInputKeyboard *ev)
{
	Key k = ev->GetKey();
	Log("Key pressed: %d", k.GetValue());

	if (ev->IsAltLeftPressed()) Log("< ALT");
	if (ev->IsAltRightPressed()) Log("> ALT");
	if (ev->IsShiftLeftPressed()) Log("< SHIFT");
	if (ev->IsShiftRightPressed()) Log("> SHIFT");
	if (ev->IsControlLeftPressed()) Log("< CONTROL");
	if (ev->IsControlRightPressed()) Log("> CONTROL");
	if (ev->IsCapsLockOn()) Log("Caps Lock is ON");
	if (ev->IsNumLockOn()) Log("Num Lock is ON");
	if (ev->IsNumericPad()) Log("NUMERIC PAD");

	if (k == Seed::KeyEscape)
		pSystem->Shutdown();

	if (k == Seed::KeyF9)
	{
		glMyResources.Unload(Seed::ObjectImage);
		if (!b)
			pScreen->SetMode(Screen::SCREEN_1024X768X32FS_OPENGL);
		else
			pScreen->SetMode(Screen::SCREEN_WII);
		b = !b;
		glMyResources.Reload(Seed::ObjectImage);
	}

	if (k == Seed::KeyF5)
	{
		glMyResources.Unload(Seed::ObjectImage);
		pScreen->ToggleFullscreen();
		glMyResources.Reload(Seed::ObjectImage);
	}

	strText.Initialize((WideString)L"Code: [%d] Ascii: [%c]");
	strText.Set((WideString)L"%d", k.GetValue()).Set((WideString)L"%c", (char)k.GetValue());
	if (k.IsCharacter())
		lblMessage.SetText(strText);
}

void MyGame::OnInputKeyboardRelease(const EventInputKeyboard *ev)
{
	Log("Key released: %d", ev->GetKey().GetValue());
}
