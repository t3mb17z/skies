#include "sky/engine/vector.h"
#include "sky/engine/physics.h"

void Sky_PhysicsApplyGravity(Sky_Vector2 *pos, Sky_Vector2 *vel, float gravity, float deltaTime) {
  float screenGravity = gravity * 100;
  pos->y += vel->y * deltaTime + 0.5f * screenGravity * deltaTime * deltaTime;
  vel->y += screenGravity * deltaTime;
}
