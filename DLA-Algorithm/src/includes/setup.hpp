#include "../../raylib/includes/raylib.h"
#include <stdlib.h>

#ifndef __SETUP_HPP__
#define __SETUP_HPP__

typedef struct screenResolution {
    int screenWidth;
    int screenHeight;
} Screen;

typedef struct cell {
    bool isOccupied;
} Cell;
typedef struct grid {
    int rows; int cols;
    int celWidth;
    int offset;
    Cell **cell;
} Grid;

Screen setupWindow(int width, int height);

Grid setupGrid(Screen screen);



#endif