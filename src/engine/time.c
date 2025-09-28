#include <SDL2/SDL.h>

#include "sky/engine/time.h"

float Sky_DeltaTime(void) {
  static Uint64 LAST = 0;
  Uint64 NOW = SDL_GetPerformanceCounter();

  float delta = (LAST > 0)
    ? (NOW - LAST) / (float)SDL_GetPerformanceFrequency()
    : 0.0f;
  LAST = NOW;

  return delta;
}
