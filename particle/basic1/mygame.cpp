#include "mygame.h"

const char *table[] = {
	"particle/basic1/particle1.psi",
	"particle/basic1/particle2.psi",
	"particle/basic1/particle3.psi",
	"particle/basic1/particle4.psi",
	"particle/basic1/particle5.psi",
	"particle/basic1/particle6.psi",
	"particle/basic1/particle7.psi",
	"particle/basic1/particle8.psi",
	"particle/basic1/particle9.psi"
};

MyGame::MyGame()
	: DemoBase()
	, cEmitter()
{
}

MyGame::~MyGame()
{
	cEmitter.Unload();
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	cEmitter.Load(table[2]);
	cEmitter.SetSprite(SPT_PARTICLE);
	cEmitter.SetPriority(10);
	cEmitter.SetPosition(0.5f, 0.5f);
	cEmitter.SetParticlesBuffer(&cParticles[0], 500);
	cEmitter.Play();
	cScene.Add(&cEmitter);
	pParticleManager->Add(&cEmitter);

	return TRUE;
}

void MyGame::OnInputKeyboardRelease(const EventInputKeyboard *ev)
{
	DemoBase::OnInputKeyboardRelease(ev);

	Key k = ev->GetKey();

	if (k.IsNumber())
	{
		u32 v = k.GetValue() - '1';
		if (v >= 0 && v < 9)
		{
			cEmitter.Load(table[v]);
		}
	}
	else
	{
		u32 v = k.GetValue() - static_cast<u32>(Seed::KeyF1);
		if (v >= 0 && v < 15)
			cEmitter.SetAnimation(v);
	}
}
