#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
	, sfxHelloWorld()
	, sfxPickup()
	, sfxTheme()
	, musTheme()
	, musTheme2()
	, iCount(0)
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

/*
	sfxTheme.Load("theme.adpcm");
	sfxTheme.SetVolume(0.1f);
	sfxTheme.SetLoop(TRUE);
	sfxTheme.Play();
	pSoundSystem->Add(&sfxTheme);
*/

	sfxHelloWorld.Load(SFX_HELLOWORLD);
	pSoundSystem->Add(&sfxHelloWorld);

	sfxPickup.Load(SFX_PICKUP_ITEM);
	pSoundSystem->Add(&sfxPickup);

	pSoundSystem->SetSfxVolume(0.5f);
	pSoundSystem->SetMusicVolume(0.5f);

	sfxHelloWorld.Play();
	sfxPickup.SetVolume(0.1f);
	
	musTheme.Load(BGM_THEME);
	musTheme.SetVolume(0.5f);
	musTheme.SetAutoUnload(TRUE);
	pSoundSystem->PlayMusic(&musTheme, 500);
	Log("1");

	return TRUE;
}

BOOL MyGame::Update(f32 dt)
{
	iCount++;
	
	if ((iCount % 10) == 0) 
		sfxPickup.Play();

	if (iCount == 300)
	{
#if 0 // cross fade another music (in this case, the same music 0.o)
		musTheme2.Load(BGM_THEME);
		musTheme2.SetVolume(0.5f);
		musTheme2.SetAutoUnload(TRUE);
		pSoundSystem->PlayMusic(&musTheme2, 500);
#else
		pSoundSystem->StopMusic(500);
#endif
		Log("2");
	}
	else if (iCount == 600)
	{
		musTheme.Load(BGM_THEME);
		musTheme.SetVolume(0.5f);
		musTheme.SetAutoUnload(TRUE);
		pSoundSystem->PlayMusic(&musTheme, 500);
		Log("1");
		iCount = 0;
	}

	return TRUE;
}

