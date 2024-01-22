#include "includes/setup.hpp"

Screen setupWindow(int width, int height) {
    Screen screen = { width, height };
    InitWindow(screen.screenWidth, screen.screenHeight, "Procedural Generation");
    ToggleFullscreen();
    return screen;
}

Grid setupGrid(Screen screen) {
    int width = 6;
    Grid newGrid;
    newGrid.celWidth = width;
    newGrid.rows = screen.screenHeight / (newGrid.celWidth);
    newGrid.cols = screen.screenWidth / (newGrid.celWidth);
    newGrid.offset = 1;

    newGrid.cell = (Cell **) calloc(newGrid.cols, sizeof(Cell*));

    for (int i = 0; i < newGrid.cols; i++) 
        newGrid.cell[i] = (Cell *) calloc(newGrid.rows, sizeof(Cell));

    for (int i = 0; i < newGrid.cols; i++) {
        for (int j = 0; j < newGrid.rows; j++) {
            newGrid.cell[i][j].isOccupied = false;
        }
    }

    return newGrid;
}