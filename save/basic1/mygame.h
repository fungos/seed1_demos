#ifndef __MYGAME_H__
#define __MYGAME_H__

#include <Seed.h>
#include "../../common/demobase.h"

using namespace Seed;

#define MAX_FOLDER_SIZE 4096

class MyGame : public DemoBase
{
	public:
		MyGame();
		~MyGame();

		virtual void Setup(int argc, char **argv);
		virtual BOOL Initialize();

		BOOL SaveSystemFlow();

	private:
		SEED_DISABLE_COPY(MyGame);

	private:
		Label		lblMessage;
		Font		fntMain;

		char pcSaveGameFolder[MAX_FOLDER_SIZE];
};

#endif // __MYGAME_H__
