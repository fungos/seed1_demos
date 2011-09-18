#include "myapp.h"

MyApp::MyApp()
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

BOOL MyApp::Initialize()
{
	pMyGame = New(MyGame);
	return pMyGame->Initialize() && IGameApp::Initialize();
}

BOOL MyApp::Shutdown()
{
	BOOL r = pMyGame->Shutdown();

	Delete(pMyGame);

	return r && IGameApp::Shutdown();
}

BOOL MyApp::Update(f32 dt)
{
	return pMyGame->Update(dt);
}

BOOL MyApp::HasError() const
{
	return pMyGame->HasError();
}

