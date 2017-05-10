#ifndef GAME_H
#define GAME_H

#include <TlHelp32.h>
#include "Memory.h"

class Game
{
    public:
        Game(string name);
        DWORD getlocal();
        Memory createMem();

    protected:

    private:
        int strcompare(const char* One, const char* Two, bool CaseSensitive);
        MODULEENTRY32 GetModuleInfo(DWORD ProcessID, const char* ModuleName);
        HWND hwnd;
        DWORD procID;

};

#endif // GAME_H
