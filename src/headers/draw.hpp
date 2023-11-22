#include "raylib.h"
#include "player.hpp"

class Draw {
  public:
  void player()
  {
    DrawRectangle(player.x, player.y, 10, 10, BlACK);
  }
};