#ifndef PLAYER_H
#define PLAYER_H

#include "Memory.h"

class Player
{
    public:
        Player(DWORD address, Memory m);
        byte getFlags();
        void jump();
        int getHealth();

    protected:

    private:
        DWORD localPlayer;
        int m_Health;
        byte m_fFlags;
        Memory mem;

        //offsets
        DWORD oJump;
        DWORD oHealth;
        DWORD oFlags;
};

#endif // PLAYER_H
