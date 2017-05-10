#ifndef MEMORY_H
#define MEMORY_H

#include <Windows.h>

class Memory
{
    public:
        Memory(HANDLE h, MODULEENTRY32 c, MODULEENTRY32 e);
        ~Memory();
        HANDLE handle;
        MODULEENTRY32 client, engine;
        template<typename T> T Memory::RPM(DWORD address);
        template<typename T> void Memory::WPM(DWORD address, T value);
    protected:

    private:
};

#endif // MEMORY_H
