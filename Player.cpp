#include "Player.h"

Player::Player(DWORD address, Memory m)
{
    //ctor
    localPlayer = address;
    mem = m;

    oJump = 0x4F3B3C;
    oHealth = 0x2C8;
    oFlags = 0x54;
}

byte Player::getFlags()
{
    return mem.RPM<byte>(localPlayer + oFlags);
}

int Player::getHealth()
{
    return mem.RPM<int>(localPlayer + oHealth);
}

void Player::jump()
{
    mem.WPM<int>(mem.client + oJump, 6);
}
