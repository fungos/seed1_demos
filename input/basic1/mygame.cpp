#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
	, bToggle(FALSE)
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();
	pSystem->SetLanguage(Seed::en_US);

	fntMain.Load(FNT_FONT1, &glDemoResources);
	lblMessage.SetFont(&fntMain);
	lblMessage.SetPriority(1);
	lblMessage.SetPosition(0.0f, 0.55f);
	lblMessage.SetWidth(1.0f);
	lblMessage.SetAlignment(HorizontalAlignCenter);
	pGuiManager->Add(&lblMessage);
	pRenderer->Add(&lblMessage);

	Log("Is Motion: %s", pInput->IsMotion() ? "Yes" : "No");
	Log("Is Pointer: %s", pInput->IsPointer() ? "Yes" : "No");
	Log("Is Joystick: %s", pInput->IsJoystick() ? "Yes" : "No");
	Log("Is Keyboard: %s", pInput->IsKeyboard() ? "Yes" : "No");

	return TRUE;
}

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
		glDemoResources.Unload(Seed::ObjectImage);
		if (!bToggle)
			pScreen->SetMode(Screen::SCREEN_1024X768X32FS_OPENGL);
		else
			pScreen->SetMode(Screen::SCREEN_WII);
		bToggle = !bToggle;
		glDemoResources.Reload(Seed::ObjectImage);
	}

	if (k == Seed::KeyF5)
	{
		glDemoResources.Unload(Seed::ObjectImage);
		pScreen->ToggleFullscreen();
		glDemoResources.Reload(Seed::ObjectImage);
	}

	strText.Initialize(DIC_INPUTTEST);
	strText.Set(DIC_VAR_CODE, k.GetValue()).Set(DIC_VAR_CHAR, (char)k.GetValue());
	if (k.IsCharacter())
		lblMessage.SetText(strText);
}

void MyGame::OnInputKeyboardRelease(const EventInputKeyboard *ev)
{
	Log("Key released: %d", ev->GetKey().GetValue());
	DemoBase::OnInputKeyboardRelease(ev);
}
