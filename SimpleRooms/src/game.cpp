#include "../raylib/includes/raylib.h"
#include "includes/setup.hpp"
#include "includes/room.hpp"

#define MAX_ROOMS 12

int main(void) {
  Screen screen = setupWindow(1920,1080);
  int roomsNum = 0;
  Room rooms[MAX_ROOMS];
  Room generatedRoom;


  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    if (IsKeyPressed(KEY_C)) {
      if (roomsNum < MAX_ROOMS) {
        generatedRoom = createRandomRoom(screen, rooms, MAX_ROOMS, &roomsNum);
      }
    }

    for (int i = 0; i < roomsNum; i++) {
      DrawRectangleV(rooms[i].position, rooms[i].size, rooms[i].color);
      if (roomsNum != MAX_ROOMS) DrawRectangleV({ rooms[i].center.x - 5, rooms[i].center.y - 5 }, { 10, 10 }, RED);
    }

    if (roomsNum == MAX_ROOMS) {
      connectRooms(rooms, roomsNum);
    } 

    DrawText(TextFormat("rooms: %d", roomsNum), 10, 10, 20, RED);
    DrawText(TextFormat("target rooms: %d", MAX_ROOMS), 10, 30, 20, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
