#include "Memory.h"

Memory::Memory(HANDLE h, MODULEENTRY32 c, MODULEENTRY32 e)
{
    //ctor
    handle = h;
    client = c;
    engine = e;
}

Memory::~Memory()
{
    //dtor
}

template<typename T> T Memory::RPM(DWORD address)
{
    T value = ReadProcessMemory(handle, (LPVOID)address, &value, sizeof(T), 0);
    return value;
}

template<typename T> void Memory::WPM(DWORD address, T value)
{
    WriteProcessMemory(handle, (LPVOID)address, &value, sizeof(T), 0);
}
