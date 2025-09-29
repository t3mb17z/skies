#include "sky/engine/collision.h"

int Sky_AABB(SDL_Rect a, SDL_Rect b) {
  return (
    a.x < b.x + b.w &&
    a.x + a.w > b.x &&
    a.y < b.y + b.h &&
    a.y + a.h > b.y
  );
}

Sky_CollisionType Sky_Collision(SDL_Rect player, SDL_Rect object) {
  if(!Sky_AABB(player, object)) return SKY_COLLISION_NONE;
  int fromLeft = (player.x + player.w) - object.x;
  int fromRight = (object.x + object.w) - player.x;
  int fromTop = (player.y + player.h) - object.y;
  int fromBottom = (object.y + object.h) - player.y;

  int minOverlap = fromLeft;
  Sky_CollisionType type = SKY_COLLISION_LEFT;

  if(fromRight < minOverlap) {
    minOverlap = fromRight;
    type = SKY_COLLISION_RIGHT;
  }

  if(fromTop < minOverlap) {
    minOverlap = fromTop;
    type = SKY_COLLISION_TOP;
  }

  if(fromBottom < minOverlap) {
    minOverlap = fromBottom;
    type = SKY_COLLISION_BOTTOM;
  }

  return type;
}
