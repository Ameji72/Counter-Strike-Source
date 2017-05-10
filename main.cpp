#include <iostream>
#include "Game.h"
#include "Player.h"

using namespace std;

int main()
{
    Game css("Counter-Strike Source"); //Creates a game object

    Player me(css.getlocal(), css.createMem()); //Creates a player object

    while (!GetAsyncKeyState(0x23))
    {
        if(GetAsyncKeyState(0x20) && (me.getFlags() & (1<<0))
        {
            me.jump();
        }
    }

    return 0;
}
