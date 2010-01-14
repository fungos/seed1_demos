#include "mygame.h"

void CorrectGamma(float p_Gamma)
{
	HDC l_DisplayHDC = GetDC(NULL);

	if (l_DisplayHDC != NULL)
	{
		WORD l_GammaRamp[3][256];

		for (size_t l_Index = 0; l_Index < 256; l_Index++)
		{
			int l_Value = (int)l_Index*(int((p_Gamma*0.5f+0.5f)*255)+128);
			l_Value = l_Value > 65535 ? 65535 : l_Value;

			l_GammaRamp[0][l_Index] =
			l_GammaRamp[1][l_Index] =
			l_GammaRamp[2][l_Index] = (WORD)l_Value;
		}

		if (SetDeviceGammaRamp(l_DisplayHDC, l_GammaRamp) == TRUE)
		{
			//m_Gamma = p_Gamma; // Store gama setting
		}
	}

	ReleaseDC(NULL, l_DisplayHDC);
}

int main(int argc, char **argv)
{
	MyGame app;

	Seed::SetGameApp(&app, argc, argv);
	Seed::Initialize();
	pScreen->ToggleFullscreen();

	//SDL_SetGamma(1.0f, 1.0f, 1.0f);
	//CorrectGamma(1.0f);

	while (!pSystem->IsShuttingDown())
	{
		Seed::Update();
	}
	Seed::Shutdown();

	//CorrectGamma(0.0f);
	return EXIT_SUCCESS;
}
