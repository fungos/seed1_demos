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
	sptLogo.SetColor(iCol, 0u, 255u, 128u);
	sptLogo.SetBlending(Seed::BlendModulate);
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
