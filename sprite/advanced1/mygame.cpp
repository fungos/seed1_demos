#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	pRenderer = new Renderer2D();
	Seed::SetRenderer(this->pRenderer);
	pScreen->SetRenderer(this->pRenderer);

	sptBg1.Load("sprite/advanced1/layer1.sprite", &glDemoResources);
	sptBg1.SetPosition(0.0f, 0.0f);
	sptBg1.SetVisible(TRUE);
	pRenderer->Add(&sptBg1);

	sptBg2.Load("sprite/advanced1/layer2.sprite", &glDemoResources);
	sptBg2.SetPosition(0.0f, 0.0f);
	sptBg2.SetVisible(TRUE);
	sptBg2.SetMasked(TRUE);
	pRenderer->Add(&sptBg2);

	sptGlassMask.Load("sprite/advanced1/glass_mask.sprite", &glDemoResources);
	sptGlassMask.SetVisible(TRUE);
	sptGlassMask.SetMask(TRUE);
	pRenderer->Add(&sptGlassMask);

	sptGlass.Load("sprite/advanced1/glass.sprite", &glDemoResources);
	sptGlass.SetVisible(TRUE);
	sptGlass.SetSpecial(TRUE);
	sptGlass.SetPriority(10);
	pRenderer->Add(&sptGlass);

	pInput->AddPointerListener(this);

	return TRUE;
}

void MyGame::OnInputPointerMove(const EventInputPointer *ev)
{
	sptGlassMask.SetPosition(ev->GetX(), ev->GetY());
	sptGlass.SetPosition(ev->GetX(), ev->GetY());
}
