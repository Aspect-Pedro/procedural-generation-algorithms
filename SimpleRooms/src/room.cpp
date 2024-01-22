#include "includes/room.hpp"

Room createRandomRoom(Screen screen, Room roomsArray[], int maxRooms, int *roomsNum) {
    int created = 0;
    int offset = 10;
    int minSize = 100;
    int maxSize = 300;
    Room newRoom;

    while (!created) {
        newRoom.position.x = GetRandomValue(offset, screen.screenWidth - offset);
        newRoom.position.y = GetRandomValue(offset, screen.screenHeight - offset);

        newRoom.size.x = GetRandomValue(minSize, maxSize);
        if (newRoom.size.x + newRoom.position.x > screen.screenWidth) continue;

        newRoom.size.y = GetRandomValue(minSize, maxSize);
        if (newRoom.size.y + newRoom.position.y > screen.screenHeight) continue;

        created = 1;
    }

    while (isOverwritten(newRoom, roomsArray, *roomsNum) ||
           newRoom.size.x + newRoom.position.x > screen.screenWidth ||
           newRoom.size.y + newRoom.position.y > screen.screenHeight) {
        newRoom.position.x = GetRandomValue(offset, screen.screenWidth - offset);
        newRoom.position.y = GetRandomValue(offset, screen.screenHeight - offset);
    }

    float randomX = GetRandomValue(newRoom.position.x + 5, newRoom.position.x + newRoom.size.x - 5);
    float randomY = GetRandomValue(newRoom.position.y + 5, newRoom.position.y + newRoom.size.y - 5);

    newRoom.center = { randomX, randomY };

    newRoom.color = WHITE;
    roomsArray[*roomsNum] = newRoom;
    *roomsNum += 1;

    return newRoom;
}

bool isOverwritten(Room room, Room roomsArray[], int maxRooms) {
    Rectangle roomRec = { room.position.x, room.position.y, room.size.x, room.size.y };
    if (maxRooms == 0) return false;
    for (int i = 0; i <= maxRooms - 1; i++) {
        Rectangle roomRec2 = { roomsArray[i].position.x, roomsArray[i].position.y, roomsArray[i].size.x, roomsArray[i].size.y };        
        if (CheckCollisionRecs(roomRec,roomRec2)) {
            return true;
        }
    }
    return false;
}

void connectRooms(Room roomsArray[], int numRooms) {
    for (int i = 0; i < numRooms - 1; i++) {
        DrawLineBezier(roomsArray[i].center, roomsArray[i + 1].center, 10.0, WHITE);
    }
}