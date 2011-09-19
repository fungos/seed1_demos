#include "demobase.h"

ISceneNode *pScene;
ISceneNode *pSceneStatic;

DemoBase::DemoBase()
	: fInfoElapsedTime(0.0f)
{
}

DemoBase::~DemoBase()
{
}

BOOL DemoBase::Initialize()
{
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

	sptLogo.Load(SPT_SEED_LOGO, pResourceManager);
	sptLogo.SetPosition(0.0f, 0.0f);
	sptLogo.SetVisible(TRUE);
	cScene.Add(&sptLogo);
	pScreen->FadeIn();

	pDefaultPool->Print();
	return TRUE;
}

BOOL DemoBase::Update(f32 dt)
{

	fInfoElapsedTime += dt;

	if (fInfoElapsedTime > 10.0f)
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

	pSceneManager->Reset();
	pRendererManager->Reset();
	pViewManager->Reset();

	pInput->RemoveKeyboardListener(this);
	pSystem->RemoveListener(this);

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
