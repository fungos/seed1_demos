#include "demobase.h"

DemoBase::DemoBase()
{
	pSystem->AddListener(this);
	pInput->AddKeyboardListener(this);

	cConfig.SetRendererDeviceType(Seed::RendererDeviceDirectX8);
	cConfig.SetVideoMode(Seed::Video_iPhoneLandscape); //Video_800x600);
	cConfig.SetFrameRate(Seed::FrameRateLockAt60);
	cConfig.SetApplicationTitle("My awesome game");
	cConfig.SetApplicationDescription("My awesome game description");
}

DemoBase::~DemoBase()
{
	pInput->RemoveKeyboardListener(this);
	pSystem->RemoveListener(this);
}

BOOL DemoBase::Initialize()
{
	IGameApp::Initialize();

	/* ------- Rendering Initialization ------- */
	cScene.SetPriority(0);
	cSceneStatic.SetPriority(20000);

	cRenderer.Add(&cScene);
	cRenderer.Add(&cSceneStatic);

	cViewport.SetRenderer(&cRenderer);
	pViewManager->Add(&cViewport);
	pRendererManager->Add(&cRenderer);

	pSceneManager->Add(&cScene);
	pSceneManager->Add(&cSceneStatic);

	pScene = &cScene;
	pSceneStatic = &cSceneStatic;
	/* ------- Rendering Initialization ------- */

	sptLogo.Load(SPT_SEED_LOGO, &cResourceManager);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	cScene.Add(&sptLogo);
	pScreen->FadeIn();

	return TRUE;
}

BOOL DemoBase::Update(f32 dt)
{
	return TRUE;
}

BOOL DemoBase::Shutdown()
{
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
