#include "Blokaroka.h"

// -- EXTERN DECLARATIONS ----------------------------------------------- //
volatile bool g_bIsAppAlive = true;
Config CONFIG;

// -- MAIN -------------------------------------------------------------- //
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR pstrCmdLine, int iCmdShow)
{

	// - - - Command Line- - - - - - - //
	if (gHandleCommandLineArgs(pstrCmdLine) == false)
	{
		return 0;
	}

	RENDER.InitRenderer(hInstance);


	// Try to read the gamestate from the best existing gamestate location.
	if (!GAMESTATE.ReadGamestate(gGetExistingSaveFilePath()))
	{
		// Gamestate was not found or it could not be read correctly, generate a new randomized gamestate.
        GAMESTATE.GenerateBricks();
    }


    RENDER.RenderFrame();
    RENDER.PresentFrame();


    while(g_bIsAppAlive)
    {
        RENDER.HandleWindows();
        Sleep(1);
    }

	// Save the gamestate in the location where it exists, or the best place for it.
    GAMESTATE.DumpGamestate(gGetExistingSaveFilePath());

    return 0;
}

// -- handleCommandLineArgs --------------------------------------------- //
/*      Command Line Argument Handling (Loop and look for args that matter)
 */
bool gHandleCommandLineArgs(PSTR pstrCmdLine)
{
    return true;
}