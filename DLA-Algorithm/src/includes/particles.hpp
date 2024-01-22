#include "../../raylib/includes/raylib.h"
#include "setup.hpp"
#include <cmath>

#ifndef __PARTICLES_HPP__
#define __PARTICLES_HPP__

typedef struct particle {
    Vector2 pos;
    Color color;
} Particle;

Particle createParticle(Grid grid);

Particle createRandomParticle(Grid grid);

bool moveParticle(Particle *particle, Grid grid);

bool moveParticleRandom(Particle *particle, Grid grid);

void drawCell(int x, int y, Grid grid, Color color);

#endif