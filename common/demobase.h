#ifndef __DEMOBASE_H__
#define __DEMOBASE_H__

#include <Seed.h>

#if defined(_SDL_)
#include "sdl/assets.h"
#elif defined(_WII_)
#include "wii/assets.h"
#elif defined(_IPHONE_)
#include "iph/assets.h"
#endif

extern ISceneNode *pScene;
extern ISceneNode *pSceneStatic;

using namespace Seed;

class DemoBase : public IGameApp, public IEventSystemListener, public IEventInputKeyboardListener
{
	public:
		DemoBase();
		~DemoBase();

		virtual BOOL Initialize();
		virtual BOOL Update(f32 dt);
		virtual BOOL Reset();
		virtual BOOL Shutdown();
		virtual BOOL HasError() const;

		// IEventSystemListener
		virtual void OnSystemShutdown(const EventSystem *ev);

		// IEventInputKeyboardListener
		virtual void OnInputKeyboardRelease(const EventInputKeyboard *ev);
		
	private:
		SEED_DISABLE_COPY(DemoBase);

	protected:
		SceneNode<1024> cScene;
		SceneNode<128> cSceneStatic;
		Array<int, 10> cArray;
		Viewport	cViewport;
		Renderer	cRenderer;
		Sprite		sptLogo;
};

#endif // __DEMOBASE_H__
