#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
	, lblMessage()
	, fntMain()
	, strText()
	, iCount(0)
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	pSystem->SetLanguage(Seed::en_US);

	strText.Set(DIC_HELLOWORLD);
	strText.Set(DIC_VAR_STR, "Seed");

	fntMain.Load(FNT_FONT1);
	lblMessage.SetFont(&fntMain);
	lblMessage.SetText(strText);
	lblMessage.SetPriority(1);
	pGuiManager->Add(&lblMessage);
	cScene.Add(&lblMessage);

	u32 len = 0;
	for (u32 id = 0; id < pDictionary->GetSize(); id++)
	{
		const WideString str = pDictionary->GetString(id, &len);
		wprintf(L"%d String: %s Size: %d\n", id, str, len);
	}

	return TRUE;
}

BOOL MyGame::Update(f32 dt)
{
	iCount++;

	if (iCount == 200)
	{
		pSystem->SetLanguage(Seed::pt_BR);
	}
	else if (iCount == 400)
	{
		pSystem->SetLanguage(Seed::en_US);
		iCount = 0;
	}

	return TRUE;
}

void MyGame::OnSystemLanguageChanged(const EventSystem *ev)
{
	// When language change event happens, you must rebuil your strings.
	strText.Set(DIC_HELLOWORLD);
	strText.Set(DIC_VAR_STR, "Seed");

	// On language change, we must reload our font so any new characters are loaded.
	fntMain.Load(FNT_FONT1); 
}
