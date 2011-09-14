#include "demobase.h"

DemoBase::DemoBase()
	: fInfoElapsedTime(0.0f)
{
	cConfig.SetRendererDeviceType(Seed::RendererDeviceDirectX8);
#if defined(_IPHONE_)
	cConfig.SetVideoMode(Seed::Video_iPhoneLandscape);
	cConfig.SetPlatformSimulation(Seed::SimulateIOS3G);
#else
	cConfig.SetVideoMode(Seed::Video_800x600);
#endif // _IPHONE_
	cConfig.SetFrameRate(Seed::FrameRateLockAt60);
	//cConfig.bDebugSprite = TRUE;
	cConfig.SetApplicationTitle("My awesome game");
	cConfig.SetApplicationDescription("My awesome game description");
	cConfig.SetPublisherName("MyPublisher");
}

DemoBase::~DemoBase()
{
}

BOOL DemoBase::Initialize()
{
	IGameApp::Initialize();

	pSystem->AddListener(this);
	pInput->AddKeyboardListener(this);

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
	fInfoElapsedTime += dt;
	if (fInfoElapsedTime > 5.0f)
	{
		Log("Memory Info: ");
		pMemoryManager->Info();

		Log("Resource Memory: ");
		pResourceManager->PrintUsedMemoryByResource();

		Log("Snapshot: ");
		pDefaultPool->Print();

		fInfoElapsedTime = 0.0f;
	}

	return TRUE;
}

BOOL DemoBase::Shutdown()
{
	sptLogo.Unload();

	pInput->RemoveKeyboardListener(this);
	pSystem->RemoveListener(this);

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
