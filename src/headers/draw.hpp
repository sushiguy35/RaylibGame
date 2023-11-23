#include "raylib.h"
#include "../player.cpp"

class Draw {
public:
    void player(const P& player)
    {
        DrawRectangle(player.x, player.y, 100, 100, BLACK);
    }
};
