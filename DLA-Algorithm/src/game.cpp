#include "../raylib/includes/raylib.h"
#include "includes/setup.hpp"
#include "includes/particles.hpp"

#define MAX_PARTICLE_NUMBER 3000
#define MAX_STEPS 20
#define CHANGE_STEPS 1

int main(void) {
  Screen screen = setupWindow(1920,1080);
  Grid grid = setupGrid(screen);
  Particle centerParticle = createParticle(grid);
  Particle particles[MAX_PARTICLE_NUMBER] = { centerParticle };
  int actualParticles = 1;
  int steps = 0;
  bool isParticleMoving = false;


  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    if (IsKeyDown(KEY_C)) {
      for (int i = 0; i < grid.cols; i++) {
        for (int j = 0; j < grid.rows; j++) {
          drawCell(i,j,grid,WHITE);
        }
      }
    }

    for (int i = 0; i < actualParticles; i++) {
      drawCell(particles[i].pos.x,particles[i].pos.y,grid,particles[i].color);
    }

    if (isParticleMoving == false) {
      Particle newParticle = createRandomParticle(grid);
      particles[actualParticles] = newParticle;
      actualParticles += 1;
      isParticleMoving = true;
    }

    if (isParticleMoving == true) {
      bool canMove;
      if (steps > CHANGE_STEPS) {
        canMove = moveParticle(&particles[actualParticles - 1],grid);
        steps += 1;
        if (steps > MAX_STEPS) steps = 0;
      } else {
        canMove = moveParticleRandom(&particles[actualParticles - 1],grid);
        steps += 1;
      } 

      DrawText(TextFormat("canMove: %d", canMove), 10, 110, 20, RED);
      
      if (!canMove) {
        isParticleMoving = false;
        grid.cell[(int)particles[actualParticles - 1].pos.x][(int)particles[actualParticles - 1].pos.y].isOccupied = true;
      } 
    }

    DrawText(TextFormat("Rows: %d", grid.rows), 10, 10, 20, RED);
    DrawText(TextFormat("Cols: %d", grid.cols), 10, 30, 20, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
