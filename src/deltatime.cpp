#include "raylib.h"

float deltatime()
{
  float dt = GetFrameTime()*GetFPS();
  return dt;
}