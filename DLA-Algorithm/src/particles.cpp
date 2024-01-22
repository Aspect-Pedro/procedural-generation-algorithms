#include "includes/particles.hpp"

Particle createParticle(Grid grid) {
    Particle newParticle;
    newParticle.color = GREEN;
    newParticle.pos.x = grid.cols / 2;
    newParticle.pos.y = grid.rows / 2;

    grid.cell[(int) newParticle.pos.x][(int) newParticle.pos.y].isOccupied = true;

    return newParticle;
}

Particle createRandomParticle(Grid grid) {
    Particle newParticle;
    int randX = GetRandomValue(2, grid.cols - 2);
    int randY = GetRandomValue(2, grid.rows - 2);
    newParticle.color = GREEN;
    newParticle.pos.x = randX;
    newParticle.pos.y = randY;

    if (grid.cell[(int)newParticle.pos.x][(int)newParticle.pos.y].isOccupied) return createParticle(grid);
    return newParticle;    
}

bool moveParticle(Particle *particle, Grid grid) {
    // 0 - right
    // 1 - bottom
    // 2 - left
    // 3 - top
    int randomDirection = GetRandomValue(0,3);
    Vector2 centerPosition = { grid.cols / 2, grid.rows / 2 };
    Vector2 distance = { abs((*particle).pos.x - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };

    if (randomDirection == 0) {
        if ((*particle).pos.x + 1 < grid.cols - 1) {
            if (grid.cell[(int)(*particle).pos.x + 1][(int)(*particle).pos.y].isOccupied) return false;
        } 

        Vector2 newDistance = { abs(((*particle).pos.x + 1) - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };
        if ((*particle).pos.x + 1 < grid.cols &&
            newDistance.x < distance.x) (*particle).pos.x += 1;
        return true;
    }

    if (randomDirection == 1) {
        if ((*particle).pos.y + 1 < grid.rows - 1) {
            if (grid.cell[(int)(*particle).pos.x][(int)(*particle).pos.y + 1].isOccupied) return false;
        }

        Vector2 newDistance = { abs((*particle).pos.x - centerPosition.x), abs(((*particle).pos.y + 1) - centerPosition.y) };
        if ((*particle).pos.y + 1 < grid.rows &&
            newDistance.y < distance.y) (*particle).pos.y += 1;
        return true;
    }

    if (randomDirection == 2) {
        if ((*particle).pos.x - 1 > 0) {
            if (grid.cell[(int)(*particle).pos.x - 1][(int)(*particle).pos.y].isOccupied) return false;
        }

        Vector2 newDistance = { abs(((*particle).pos.x - 1) - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };
        if ((*particle).pos.x - 1 > 0 &&
            newDistance.x < distance.x) (*particle).pos.x -= 1;
        return true;
    }

    if (randomDirection == 3) {
        if ((*particle).pos.y - 1 > 0) {
            if (grid.cell[(int)(*particle).pos.x][(int)(*particle).pos.y - 1].isOccupied) return false;
        }

        Vector2 newDistance = { abs((*particle).pos.x - centerPosition.x), abs(((*particle).pos.y - 1) - centerPosition.y) };        
        if ((*particle).pos.y - 1 > 0 &&
            newDistance.y < distance.y) (*particle).pos.y -= 1;
        return true;
    }

    return true;
}

void drawCell(int x, int y, Grid grid, Color color) {
    DrawRectangle(x * grid.celWidth, y * grid.celWidth,grid.celWidth - grid.offset,grid.celWidth - grid.offset, color);
}

bool moveParticleRandom(Particle *particle, Grid grid) {
    // 0 - right
    // 1 - bottom
    // 2 - left
    // 3 - top
    int randomDirection = GetRandomValue(0,3);
    Vector2 centerPosition = { grid.cols / 2, grid.rows / 2 };
    Vector2 distance = { abs((*particle).pos.x - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };

    if (randomDirection == 0) {
        if ((*particle).pos.x + 1 < grid.cols - 1) {
            if (grid.cell[(int)(*particle).pos.x + 1][(int)(*particle).pos.y].isOccupied) return false;
        } 

        Vector2 newDistance = { abs(((*particle).pos.x + 1) - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };
        if ((*particle).pos.x + 1 < grid.cols) (*particle).pos.x += 1;
        return true;
    }

    if (randomDirection == 1) {
        if ((*particle).pos.y + 1 < grid.rows - 1) {
            if (grid.cell[(int)(*particle).pos.x][(int)(*particle).pos.y + 1].isOccupied) return false;
        }

        Vector2 newDistance = { abs((*particle).pos.x - centerPosition.x), abs(((*particle).pos.y + 1) - centerPosition.y) };
        if ((*particle).pos.y + 1 < grid.rows) (*particle).pos.y += 1;
        return true;
    }

    if (randomDirection == 2) {

        if ((*particle).pos.x - 1 > 0) {
            if (grid.cell[(int)(*particle).pos.x - 1][(int)(*particle).pos.y].isOccupied) return false;
        }

        Vector2 newDistance = { abs(((*particle).pos.x - 1) - centerPosition.x), abs((*particle).pos.y - centerPosition.y) };
        if ((*particle).pos.x - 1 > 0) (*particle).pos.x -= 1;
        return true;
    }

    if (randomDirection == 3) {

        if ((*particle).pos.y - 1 > 0) {
            if (grid.cell[(int)(*particle).pos.x][(int)(*particle).pos.y - 1].isOccupied) return false;
        }

        Vector2 newDistance = { abs((*particle).pos.x - centerPosition.x), abs(((*particle).pos.y - 1) - centerPosition.y) };        
        if ((*particle).pos.y - 1 > 0) (*particle).pos.y -= 1;
        return true;
    }

    return true;
}
