#include "Hero.hpp"

const int enemiesdamage = 10;
const int artifacthp = 5;
const int artifactdmg = 1;
const int artifactrange = 2;

Hero::Hero() : Character(def, herostarty, herostartx,'P')
{	
    artifact = Artifact (y, x,'H');
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->maxReload = 8;
    this->range = 15;
    this->speed = 1;
    this->dmg = 15;
    this->reload = 0;
}

Hero::Hero(int y=0, int x=0) : Character(def, y, x,'P')
{   
    artifact = Artifact (y, x,'H');
    this->key = 1;
    this->maxHp=30;
    this->hp = this->maxHp;
    this->maxReload=8;
    this->reload=maxReload;
    this->range = 15;
    this->speed = 1;
    this->dmg = 15;
    this->reload = 0;
}

/*
Hero::Hero(const Hero& h) 
{
    y=1;x=1;icon='P';cur_direction=def;
}*/

//per l'inizializzazione della classe
void Hero::tankClass() 
{
    this->maxHp=40;
    this->hp = this->maxHp;
    this->ac = 3;
    this->dmg = 2;
    this->speed = 1;
    this->maxReload=3;
    this->reload=maxReload;
    this->range = 2;
}

void Hero::rogueClass() 
{
    this->maxHp=20;
    this->hp = this->maxHp;
    this->ac = 2;
    this->dmg = 3;
    this->speed = 4;
    this->maxReload=2;
    this->reload=maxReload;
    this->range = 2;
}

void Hero::rangerClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->dmg = 1;
    this->speed = 3;
    this->maxReload=1;
    this->reload=maxReload;
    this->range = 10;
}

void Hero::mageClass() 
{
    this->maxHp=16;
    this->hp = this->maxHp;
    this->ac = 1;
    this->dmg = 3;
    this->speed = 2;
    this->maxReload=4;
    this->reload=maxReload;
    this->range = 8;
}

void Hero::useAbility() 
{
}

void Hero::attack(Board &board_win, Direction dir) 
{
    if(getReload()<=0){
        setReload(getMaxReload());
        Projectile *new_proj = new Projectile(dir,getx(),gety(), 'o');
        projectile.push_back(new_proj); 
        switch(dir){
            case up:
                new_proj->setIcon('|');
                break;
            case down:
                new_proj->setIcon('|');
                break;
            case dx:
                new_proj->setIcon('-');
                break;
            case sx:
                new_proj->setIcon('-');
                break;
        }
    }
}

//per movimento proiettili e check di colpito o out of range


void Hero::centerHero(Direction dir) {
	switch(dir){
    case(sx):
        setx(BOARD_COLS-2);
        sety(BOARD_ROWS/2);
        break;
    case (dx):
        setx(1);
        sety(BOARD_ROWS/2);
        break;
    case (up):
        setx(herostartx);
        sety(BOARD_ROWS-2);
        break;
    case (down):
        setx(herostartx);
    	sety(1);
        break;
    default:
        setx(herostartx);
    	sety(herostarty);
        break;
    }
}

bool Hero::useKey()
{
    if(getKey() >= 1)
    {
        addKey(-1);
        return true;
    }
    else return false;
}

void Hero::setKey(int key){
    this->key=key;
}

int Hero::getKey(){
    return this->key;
}

void Hero::addKey(int key){
    setKey(getKey()+key);
}


void Hero::heal(int artifactHp){
    if(getHp()+artifactHp<=getMaxHp()){
    setHp(getHp()+artifactHp);
    }
    else{
        setHp(getMaxHp());
        }
}

void Hero::increaseHealth(int artifactHp)
{
    setMaxHp(getMaxHp()+artifactHp);
}

void Hero::increaseDamage(int artifactDmg)
{
    setDmg(getDmg()+artifactDmg);
}

void Hero::increaseRange(int artifactRange)
{
    setRange(getRange()+artifactRange);
}

void Hero::reduceHealthHero(int enemiesDamage)
{
    setHp(getHp()-enemiesDamage);
}

bool Hero::death()
{
    if(getHp() <= 0){
        return true;
    }
    return false;
}