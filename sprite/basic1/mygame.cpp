#include "mygame.h"

MyGame::MyGame()
	: DemoBase()
	, fRot(0.0f)
	, iCol(0)
	, iCount(0)
	, bDir(TRUE)
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Update(f32 dt)
{
	sptLogo.SetColor(static_cast<u8>(iCol), 0, 255, 128);
	//sptHelloWorld.SetScale(0.5f);
	sptLogo.SetBlending(IRenderable::MODULATE);
	sptLogo.SetRotation(fRot);

	fRot += 0.5f;
	if (bDir) 
		iCol++;
	else 
		iCol--;

	if (iCol == 255)
		bDir = FALSE;

	if (iCol == 0)
		bDir = TRUE;

	if (iCount == 200)
		pScreen->FadeOut();

	if (iCount == 400)
	{
		pScreen->FadeIn();
		iCount = 0;
	}
	iCount++;

	return TRUE;
}
