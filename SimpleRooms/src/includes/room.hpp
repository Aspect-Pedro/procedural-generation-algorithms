#include "../../raylib/includes/raylib.h"
#include "setup.hpp"

#ifndef __ROOM_HPP__
#define __ROOM_HPP__

typedef struct room {
    Vector2 position;
    Vector2 size;
    Vector2 center;
    Color color;
} Room;

Room createRandomRoom(Screen screen, Room roomsArray[], int maxRooms, int *roomsNum);

bool isOverwritten(Room room, Room roomsArray[], int maxRooms);

void connectRooms(Room roomsArray[], int numRooms);


#endif