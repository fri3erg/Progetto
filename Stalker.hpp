#pragma once

//nemico stealth

#include "Enemy.hpp"
#include "Hero.hpp"

class Stalker : public Enemy
{
public:
    Stalker();
    Stalker(int y,int x,int diff);
    //per creare proiettili
     void createProjectile(Board &board_win, Character &hero, Direction dir)override;
     //per movimento proiettili e check di colpito o out of range
     void checkProjectile(Board &board_win, Character &hero);
     //va a una tua stessa linea o colonna per spararti e spara
     void chooseDirection(Board &board_win, Character &hero) override;
    
};