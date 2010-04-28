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

	sptBg1.Load(SPT_LAYER1, &glDemoResources);
	sptBg1.SetPosition(0.0f, 0.0f);
	sptBg1.SetVisible(TRUE);
	pRenderer->Add(&sptBg1);

	sptBg2.Load(SPT_LAYER2, &glDemoResources);
	sptBg2.SetPosition(0.0f, 0.0f);
	sptBg2.SetVisible(TRUE);
	sptBg2.SetMasked(TRUE);
	pRenderer->Add(&sptBg2);

	sptGlassMask.Load(SPT_GLASS_MASK, &glDemoResources);
	sptGlassMask.SetVisible(TRUE);
	sptGlassMask.SetMask(TRUE);
	pRenderer->Add(&sptGlassMask);

	sptGlass.Load(SPT_GLASS, &glDemoResources);
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
