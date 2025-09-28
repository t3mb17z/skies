#ifndef SKY_collision_h
#define SKY_collision_h

#include <SDL2/SDL_rect.h>

typedef enum {
  SKY_COLLISION_BOTTOM,
  SKY_COLLISION_TOP,
  SKY_COLLISION_LEFT,
  SKY_COLLISION_RIGHT,
  SKY_COLLISION_NONE
} Sky_CollisionType;

int Sky_AABB(SDL_Rect a, SDL_Rect b);
Sky_CollisionType Sky_Collision(SDL_Rect player, SDL_Rect object);

#endif
