#include "mygame.h"

#define MY_GAME_ID				2
#define MY_GAME_NAME_LEN		20
#define MY_GAME_RANKING_SIZE	9

struct MySlotStruct
{
	char name[MY_GAME_NAME_LEN];
	u32 level;
};

struct MyRankingStruct
{
	char	name[MY_GAME_NAME_LEN];
	u32		score;
	u32		time;
};

struct MySharedStruct
{
	MyRankingStruct entries[MY_GAME_RANKING_SIZE];
};

MyGame::MyGame()
{
}

MyGame::~MyGame()
{
}

void MyGame::Setup(int argc, char **argv)
{
	DemoBase::Setup(argc, argv);

	// FIXME: This must be done magically by the SDK, user don't care and will be pissed off to do this kind of stuff.
	// FIXME: wchar_t/char/FilePath
	{
		FilePath tmpPath[MAX_FOLDER_SIZE];
		snprintf(tmpPath, MAX_FOLDER_SIZE, "%s%s/", pSystem->GetHomeFolder(), "/MyPublisher");
		pFileSystem->MakeDirectory(tmpPath);
		snprintf(pcSaveGameFolder, MAX_FOLDER_SIZE, "%s%s/", tmpPath, cConfig.GetApplicationTitle());
		pFileSystem->MakeDirectory(pcSaveGameFolder);
		pFileSystem->SetWriteableDirectory(pcSaveGameFolder);
	}

	pSaveSystem->SetTotalSlots(5);
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();
	pSystem->SetLanguage(Seed::en_US);

	fntMain.Load(FNT_FONT1);
	lblMessage.SetFont(&fntMain);
	lblMessage.SetPriority(1);
	lblMessage.SetPosition(0.0f, 0.55f);
	lblMessage.SetWidth(1.0f);
	lblMessage.SetAlignment(HorizontalAlignCenter);
	pGuiManager->Add(&lblMessage);
	cScene.Add(&lblMessage);

	this->SaveSystemFlow();

	MySlotStruct slot, slot2, slot3;
	memset(&slot, '\0', sizeof(slot));
	memset(&slot2, '\0', sizeof(slot2));
	memset(&slot3, '\0', sizeof(slot3));
	MySharedStruct shared;
	memset(&shared, '\0', sizeof(shared));

	for (u32 i = 0; i < MY_GAME_RANKING_SIZE; i++)
	{
		strncpy(shared.entries[i].name, "Danny", MY_GAME_NAME_LEN);
		shared.entries[i].time = shared.entries[i].score = 100 - (i * 10);
	}
	lblMessage.SetText(DIC_SAVECREATED); // Move to dictionary!

	strncpy(slot.name, "Patuti", MY_GAME_NAME_LEN);
	slot.level = 10;
	pSaveSystem->Save(2, &slot);

	strncpy(slot.name, "Andressa", MY_GAME_NAME_LEN);
	slot.level = 55;
	pSaveSystem->Save(4, &slot, &shared);
	
	pSaveSystem->Load(2, &slot2, &shared);
	pSaveSystem->Load(4, &slot3);
	if (memcmp(&slot, &slot2, sizeof(slot)) == 0)
	{
		Log("Equal");
	}
	else
	{
		Log("Different");
	}

	if (memcmp(&slot, &slot3, sizeof(slot)) == 0)
	{
		Log("Equal");
	}
	else
	{
		Log("Different");
	}

	return TRUE;
}

BOOL MyGame::SaveSystemFlow()
{
	MySlotStruct slot;
	memset(&slot, '\0', sizeof(slot));
	
	MySharedStruct shared;
	memset(&shared, '\0', sizeof(shared));

	eCartridgeError error = pSaveSystem->Initialize(Seed::Cartridge512b);
	if (error == Seed::ErrorNone)
		error = pSaveSystem->Prepare(MY_GAME_ID, &slot, sizeof(slot), &shared, sizeof(shared));

	if (error == Seed::ErrorDeviceFull)
	{
		Log("Not enough space available on device.");
		lblMessage.SetText((WideString)L"Device is full"); // Move to dictionary
		return FALSE;
	}

	if (error == Seed::ErrorInodeFull)
	{
		Log("Not enough inodes available on device.");
		lblMessage.SetText((WideString)L"INode is full"); // Move to dictionary
		return FALSE;
	}

	if (error == Seed::ErrorNoCard || error == Seed::ErrorAccessDenied)
	{
		Log("Unknown file system error");
		lblMessage.SetText((WideString)L"No Card or Access Denied - pSystem->HangUp()"); // Move to dictionary
		pSystem->HangUp();
		return FALSE;
	}

	if (error == Seed::ErrorNotFormatted)
	{
		Log("Save file doesn't exist or corrupted, creating one now.");
		error = pSaveSystem->FormatCard(&slot, &shared);
	}

	if (error == Seed::ErrorDataCorrupt)
	{
		Log("One or more saved games were corrupted and had to be reset");
		lblMessage.SetText((WideString)L"Data corrupted."); // Move to dictionary
		error = Seed::ErrorNone;
	}

	if (error == Seed::ErrorFilesystemCorrupt)
	{
		Log("File system became corrupted");
		lblMessage.SetText((WideString)L"Filesystem corrupted - pSystem->HangUp()."); // Move to dictionary
		pSystem->HangUp();
		return FALSE;
	}

	if (error == Seed::ErrorNone)
	{
		Log("Save data CRC ok.");
		// Do your initial loading here.
		return TRUE;
	}

	return FALSE;
}
