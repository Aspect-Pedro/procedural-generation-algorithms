g++ src/game.cpp src/setup.cpp src/room.cpp -o play -O1 -Wall -Wno-missing-braces -I raylib/includes/ -L raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

.\play