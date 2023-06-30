#ifndef GAME_H
#define GAME_H

#include "lib.h"

class Game{
public:
    Game();
    ~Game();

    void start();

    void loadMap();
    void drawMap();

    void loadEnemyTanks();
    void drawEnemyTanks();

private:
    int score = 0;

    
};

#endif