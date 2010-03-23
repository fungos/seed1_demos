#include "mygame.h"

#define BTN_ID1		1
#define BTN_ID2		2
#define BTN_ID3		3

MyGame::MyGame()
	: DemoBase() 
	, btnRect()
	, btnPixel()
	, btnMask()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	// Collision by rect area
	btnRect.Initialize(BTN_ID3);
	btnRect.SetPosition(0.28f, 0.4f);
	btnRect.Load("gui/basic2/btn_mask.button", &glDemoResources);
	btnRect.SetCollisionType(Seed::CollisionByRectangle);
	btnRect.AddListener(this);
	pRenderer->Add(&btnRect);
	pGuiManager->Add(&btnRect);

	// Collision by pixel alpha
	btnPixel.Initialize(BTN_ID2, Seed::CollisionByPixel);
	btnPixel.SetPosition(0.62f, 0.4f);
	btnPixel.Load("gui/basic2/btn_mask.button", &glDemoResources);
	btnPixel.AddListener(this);
	pRenderer->Add(&btnPixel);
	pGuiManager->Add(&btnPixel);

	// Collision by mask
	btnMask.Load("gui/basic2/btn_mask.button", &glDemoResources);
	btnMask.AddListener(this);
	pRenderer->Add(&btnMask);
	pGuiManager->Add(&btnMask);

	return TRUE;
}

void MyGame::OnWidgetPress(const EventWidget *ev)
{
	switch (ev->GetSender()->GetId())
	{
		case BTN_ID1:
		{
			Log("Button 1 Mask - Pressed!");
		}
		break;

		case BTN_ID2:
		{
			Log("Button 2 Pixel - Pressed!");
		}
		break;

		case BTN_ID3:
		{
			Log("Button 3 Rect - Pressed!");
		}
		break;

		default:
		break;
	}
}
