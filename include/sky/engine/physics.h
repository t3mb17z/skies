#ifndef SKY_physics_h
#define SKY_physics_h

#include <sky/engine/vector.h>

void Sky_PhysicsApplyGravity(Sky_Vector2 *pos, Sky_Vector2 *vel, float gravity, float deltaTime);

#endif
