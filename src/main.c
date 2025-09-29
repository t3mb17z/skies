#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

#include "sky/engine/physics.h"
#include "sky/engine/time.h"
#include "sky/engine/vector.h"
#include "sky/engine/collision.h"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char **argv) {

  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not initialize video and audio subsystem\n");
    return 1;
  }

  SDL_Window *window;
  SDL_Renderer *render;

  window = SDL_CreateWindow("Centered", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if(window == NULL) {
    fprintf(stderr, "Could not open window\n");
    return 1;
  }

  render = SDL_CreateRenderer(window, -1, 0);
  if(render == NULL) {
    fprintf(stderr, "Could not create renderer");
    return 1;
  }
  SDL_Rect player = {
    .h = 50, .w = 50, .x = 0, .y = 0
  };
  SDL_Rect floorRect = {
    .h = 20, .w = WIDTH, .x = 0, .y = HEIGHT - 20
  };
  Sky_Vector2 playerPos = { .x = 0, .y = 0 };
  Sky_Vector2 playerVel = { .x = 240, .y = 0 };
  int isJumping = 0, isOsGround = 0, jumped = 0;

  SDL_Event event;
  int running = 1;
  while(running) {

    float deltaTime = Sky_DeltaTime();
    Sky_CollisionType type;

    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = 0;
      }
    }

    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    if(keys[SDL_SCANCODE_A]) playerPos.x -= playerPos.x >= 0 ? playerVel.x * deltaTime : 0;
    if(keys[SDL_SCANCODE_D]) playerPos.x += playerPos.x <= WIDTH - player.h ? playerVel.x * deltaTime : 0;
    if(keys[SDL_SCANCODE_SPACE] && !isJumping && !jumped && isOsGround) {
      isJumping = 1, isOsGround = 0, jumped = 1;
      playerVel.y = -540;
    }
    if(!keys[SDL_SCANCODE_SPACE] && isOsGround){
      jumped = 0;
    }

    Sky_PhysicsApplyGravity(&playerPos, &playerVel, 9.81f, deltaTime);

    player.x = (int)round(playerPos.x);
    player.y = (int)round(playerPos.y);

    type = Sky_Collision(player, floorRect);
    if(type == SKY_COLLISION_TOP) {
      playerPos.y = floorRect.y - player.h;
      playerVel.y = 0;
      isJumping = 0, isOsGround = 1;
    } else if(type == SKY_COLLISION_NONE) {
      
    }

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderFillRect(render, &player);
    SDL_RenderFillRect(render, &floorRect);

    SDL_RenderPresent(render);

    // printf("\r\x1b[0K%f", deltaTime);
  }

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
