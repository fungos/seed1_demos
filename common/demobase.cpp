#include "demobase.h"

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
	pScreen->Setup(Screen::SCREEN_800X600X32W_OPENGL);
	pSystem->SetFrameRate(ISystem::RATE_60FPS);
	pSystem->SetApplicationTitle("My awesome game");
	pSystem->SetApplicationDescription("My awesome game description");
}

BOOL DemoBase::Initialize()
{
	IGameApp::Initialize();

	pRenderer = New(Renderer2D());

	Seed::SetRenderer(pRenderer);
	pScreen->SetRenderer(pRenderer);

	sptLogo.Load(SPT_SEED_LOGO, &cResourceManager);
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
	Delete(pRenderer);
	return IGameApp::Shutdown();
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
