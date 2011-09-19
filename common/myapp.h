#ifndef __MYAPP_H__
#define __MYAPP_H__

/*
 * MyApp is plain simple, it is needed to hold the sdk settings and the resource manager, but more important is that
 * it will guarantee that the initialization and deinitialization of all your "static" objects will be destroyed in
 * the correct order. ie. initialized after memory manager and destroyed before.
 */


class MyApp : public IGameApp
{
	public:
		MyApp()
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

		virtual BOOL Initialize()
		{
			pMyGame = New(MyGame);
			return pMyGame->Initialize() && IGameApp::Initialize();
		}

		virtual BOOL Shutdown()
		{
			BOOL r = pMyGame->Shutdown();

			Delete(pMyGame);

			return r && IGameApp::Shutdown();
		}

		virtual BOOL Update(f32 dt)
		{
			return pMyGame->Update(dt);
		}

		virtual BOOL HasError() const
		{
			return pMyGame->HasError();
		}

	private:
		MyGame *pMyGame;
};

#endif // __MYAPP_H__
