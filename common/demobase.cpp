#include "demobase.h"

ResourceManager glDemoResources("demo");

DemoBase::DemoBase()
	: pRenderer(NULL)
	, sptLogo()
{
	pSystem->AddListener(this);
	pInput->AddKeyboardListener(this);
}

DemoBase::~DemoBase()
{
	pInput->RemoveKeyboardListener(this);
	pSystem->RemoveListener(this);
}

void DemoBase::Setup(int argc, char **argv)
{
	pScreen->Setup(Screen::SCREEN_WII);
	pSystem->SetFrameRate(ISystem::RATE_60FPS);
	pSystem->SetApplicationTitle("My awesome game");
	pSystem->SetApplicationDescription("My awesome game description");
}

BOOL DemoBase::Initialize()
{
	pRenderer = new Renderer2D();

	Seed::SetRenderer(pRenderer);
	pScreen->SetRenderer(pRenderer);

	sptLogo.Load("sprite/basic1/seed_logo.sprite", &glDemoResources);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	pRenderer->Add(&sptLogo);
	pScreen->FadeIn();

	return TRUE;
}

BOOL DemoBase::Update(f32 dt)
{
	return TRUE;
}

BOOL DemoBase::Shutdown()
{
	glDemoResources.Reset();

	if (pRenderer)
		delete pRenderer;
	pRenderer = NULL;

	return TRUE;
}

BOOL DemoBase::Reset()
{
	return TRUE;
}

BOOL DemoBase::HasError() const
{
	return FALSE;
}

void DemoBase::OnSystemShutdown(const EventSystem *ev)
{
	pSystem->Shutdown();
}

void DemoBase::OnInputKeyboardRelease(const EventInputKeyboard *ev)
{
	Key k = ev->GetKey();

	if (k == Seed::KeyEscape)
		pSystem->Shutdown();
}
