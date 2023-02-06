#pragma once

#include "Hero.hpp"
#include "Projectile.hpp"
#include <vector>

class Enemy : public Character {
protected: 
    bool isBoss=false;
    bool isFlyer=false;
    int bomb_reload=10;
    int enemy_reload=5;
    int enemy_memory=7;
    int enemy_range=11;
    int melee_range=3;
    int melee_enemy_reload=5;
    int sight_range= 20;
    int default_coord_x= 10;
    int default_coord_y=10;
    int boom_range=5;
    int mem=0;
    int reload=0;
    int timer=10;
    bool timeractivated=false;
    int difficulty=0;
    int difficultylevel=0;
    int ammo=2;
    int hp=30;
    int dmg=5;
public:
    std::vector<Projectile*> projectile;
    Enemy(Direction dir, int y, int x ,chtype ch,int diff);
    virtual void createProjectile(Board &board_win, Hero &hero, Direction dir) {}
    virtual void checkProjectile(Board &board_win, Hero &hero) {}
    
    // metodo astratto per scelta automatica di direzione dei nemici
	virtual void chooseDirection(Board &board_win, Hero &hero) {}

    bool checkBoss();
    void makeBoss(int hp_multiplier,int range_multiplier, int dmg_multiplier);
    bool getisFlyer();
    void setisFlyer(bool set);
    bool hasLos(Board &board_win, Hero &hero);
    bool flyerHasLos(Board &board_win, Hero &hero);
    bool inSight(int distancex,int distancey);
    void reduceHealthEnemy(int heroDmg);
    int getHp ();
};  

typedef Enemy * pEn;