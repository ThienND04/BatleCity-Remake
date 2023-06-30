OBJS = src/*
# ti them sau ...

CC = g++

LINKER_FLAG = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

all:
	g++ -I src/include/SDL2 -L src/lib ${OBJS} ${LINKER_FLAG} -o bin/game.exe
	