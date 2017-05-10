#include "Game.h"
#include <iostream>

int Game::strcompare(const char* One, const char* Two, bool CaseSensitive)
{
    #if defined _WIN32 || defined _WIN64
    return CaseSensitive ? strcmp(One, Two) : _stricmp(One, Two);
    #else
    return CaseSensitive ? strcmp(One, Two) : strcasecmp(One, Two);
    #endif
}

MODULEENTRY32 Game::GetModuleInfo(DWORD ProcessID, const char* ModuleName)
{
    void* hSnap = nullptr;
    MODULEENTRY32 Mod32 = {0};

    if ((hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID)) == INVALID_HANDLE_VALUE)
        return Mod32;

    Mod32.dwSize = sizeof(MODULEENTRY32);
    while (Module32Next(hSnap, &Mod32))
    {
        if (!strcompare(ModuleName, Mod32.szModule, false))
        {
            CloseHandle(hSnap);
            return Mod32;
        }
    }

    CloseHandle(hSnap);
    return {0};
}


Game::Game(string name)
{
    //ctor
    cout << "Running hack for " << name << " by Ameji72\n";
    hwnd = FindWindowA(NULL, name); cout << "Searching for handle to window...\n"; Sleep(100); //Grabs window handle
    if (!hwnd) exit(-1);
    GetWindowThreadProcessID(hwnd, &procID); cout << "Searching for process ID...\n"; Sleep(100); //Grabs process ID
    if (!procID) exit(-1);
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); cout << "Searching for game handle, opening with all access...\n"; Sleep(100); //Grabs game handle with all access
    if (!handle) exit(-1);

    //Game access is now open

    MODULEENTRY32 client = GetModuleInfo(procID, "client.dll"); MODULEENTRY32 engine = GetModuleInfo(procID, "engine.dll"); cout << "Searching for game modules...\n"; Sleep(100);//Get module information
    if (!client || !engine) exit(-1);




}

Memory Game::createMem()
{
    Memory mem(handle, client, engine);
    return mem;
}

DWORD Game::getlocal()
{
    Memory mem = createMem();

    DWORD local = mem.RPM<DWORD>(mem.RPM<DWORD>(mem.client + 0x4E3934) + 0x35C);
    mem.~Memory();

    return local;
}
