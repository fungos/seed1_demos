#include "mygame.h"

int main(int argc, char **argv)
{
	MyGame app;

	Seed::SetGameApp(&app, argc, argv);
	if (Seed::Initialize())
	{
		while (!pSystem->IsShuttingDown())
		{
			if (!app.HasError())
			{
				Seed::Update();
			}
			pTimer->Sleep(1);
		}
	}
	Seed::Shutdown();

	return EXIT_SUCCESS;
}
