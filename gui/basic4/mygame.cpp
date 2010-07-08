#include "mygame.h"

#define BTN_ID_A1	1
#define BTN_ID_A2	2
#define BTN_ID_B1	3
#define BTN_ID_B2	4

MyGame::MyGame()
	: DemoBase()
	, lblTitleA()
	, btnBtnA1()
	, btnBtnA2()
	, wcAreaA()
	, lblTitleB()
	, btnBtnB1()
	, btnBtnB2()
	, wcAreaB()
	, strEnabled()
	, strDisabled()
	, fntMain()
	, iCount(0)
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	strEnabled.Set(DIC_ENABLED);
	strDisabled.Set(DIC_DISABLED);
	pSystem->SetLanguage(Seed::en_US);

	fntMain.Load(FNT_FONT1);

	wcAreaA.SetWidth(0.5f);
	wcAreaA.SetHeight(1.0f);
	pGuiManager->Add(&wcAreaA);

	lblTitleA.SetFont(&fntMain);
	lblTitleA.SetText(strEnabled);
	lblTitleA.SetPriority(1);
	wcAreaA.Add(&lblTitleA);
	cScene.Add(&lblTitleA);

	// Collision by rect area
	btnBtnA1.Initialize(BTN_ID_A1);
	btnBtnA1.SetSprite(SPT_BTN_SPRITE);
	btnBtnA1.SetPriority(1);
	btnBtnA1.SetPosition(0.2f, 0.2f);
	btnBtnA1.SetVisible(TRUE);
	btnBtnA1.AddListener(this);
	wcAreaA.Add(&btnBtnA1);
	cScene.Add(&btnBtnA1);

	// Collision by pixel alpha
	btnBtnA2.Initialize(BTN_ID_A2, Seed::CollisionByPixel);
	btnBtnA2.SetSprite(SPT_BTN_SPRITE);
	btnBtnA2.SetPriority(1);
	btnBtnA2.SetPosition(0.2f, 0.6f);
	btnBtnA2.SetVisible(TRUE);
	btnBtnA2.AddListener(this);
	wcAreaA.Add(&btnBtnA2);
	cScene.Add(&btnBtnA2);

	wcAreaB.SetPosition(0.5f, 0.0f);
	wcAreaB.SetWidth(0.5f);
	wcAreaB.SetHeight(1.0f);
	pGuiManager->Add(&wcAreaB);

	lblTitleB.SetFont(&fntMain);
	lblTitleB.SetText(strDisabled);
	lblTitleB.SetPriority(1);
	wcAreaB.Add(&lblTitleB);
	cScene.Add(&lblTitleB);

	// Collision by rect area
	btnBtnB1.Initialize(BTN_ID_B1);
	btnBtnB1.SetSprite(SPT_BTN_SPRITE);
	btnBtnB1.SetPriority(1);
	btnBtnB1.SetPosition(0.2f, 0.2f);
	btnBtnB1.SetVisible(TRUE);
	btnBtnB1.AddListener(this);
	wcAreaB.Add(&btnBtnB1);
	cScene.Add(&btnBtnB1);

	// Collision by pixel alpha
	btnBtnB2.Initialize(BTN_ID_B2, Seed::CollisionByPixel);
	btnBtnB2.SetSprite(SPT_BTN_SPRITE);
	btnBtnB2.SetPriority(1);
	btnBtnB2.SetPosition(0.2f, 0.6f);
	btnBtnB2.SetVisible(TRUE);
	btnBtnB2.AddListener(this);
	wcAreaB.Add(&btnBtnB2);
	cScene.Add(&btnBtnB2);

	wcAreaB.SetVisible(FALSE);
	wcAreaB.SetDisabled(TRUE);

	return TRUE;
}

BOOL MyGame::Update(f32 dt)
{
	iCount++;

	if (iCount == 300)
	{
		wcAreaA.SetDisabled(TRUE);
		lblTitleA.SetText(strDisabled);

		wcAreaB.SetDisabled(FALSE);
		wcAreaB.SetVisible(TRUE);
		lblTitleB.SetText(strEnabled);
	}
	else if (iCount == 600)
	{
		wcAreaA.SetDisabled(FALSE);
		lblTitleA.SetText(strEnabled);

		wcAreaB.SetDisabled(TRUE);
		wcAreaB.SetVisible(FALSE);
		lblTitleB.SetText(strDisabled);
		iCount = 0;
	}
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
