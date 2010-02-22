#include "mygame.h"

#define BTN_ID1		1
#define BTN_ID2		2

MyGame::MyGame()
	: DemoBase()
	, btnRect()
	, btnPixel()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	// Collision by rect area
	btnRect.Initialize(BTN_ID1);
	btnRect.SetSprite("gui/basic1/btn_sprite.sprite", &glDemoResources);
	btnRect.SetPriority(1);
	btnRect.SetPosition(0.28f, 0.4f);
	btnRect.SetVisible(TRUE);
	btnRect.AddListener(this);
	pRenderer->Add(&btnRect);
	pGuiManager->Add(&btnRect);

	// Collision by pixel alpha
	btnPixel.Initialize(BTN_ID2, Seed::CollisionByPixel);
	btnPixel.SetSprite("gui/basic1/btn_sprite.sprite", &glDemoResources);
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
