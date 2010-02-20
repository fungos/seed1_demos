#ifndef __DEMOBASE_H__
#define __DEMOBASE_H__

#include <Seed.h>

#if defined(_SDL_)
#include "sdl/assets.h"
#elif defined(_WII_)
#include "wii/assets.h"
#endif

using namespace Seed;

extern ResourceManager glDemoResources;

class DemoBase : public IGameApp, public IEventSystemListener
{
	public:
		DemoBase();
		~DemoBase();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();
		virtual BOOL Update(f32 dt);
		virtual BOOL Reset();
		virtual BOOL Shutdown();
		virtual BOOL HasError() const;

		virtual void OnSystemShutdown(const EventSystem *ev);
		
	private:
		SEED_DISABLE_COPY(DemoBase);

	protected:
		Renderer2D 	*pRenderer;
		Sprite		sptLogo;
};


#endif // __DEMOBASE_H__
