#pragma once

//nemico che spara

#include "Enemy.hpp"
#include "Projectile.hpp"


class Shooter : public Enemy
{
public:
    Shooter(int y, int x);
    //per creare proiettili
 void createProjectile(Direction dir)override { 
      chtype bullet_icon;
        if(dir%2==0){
            bullet_icon='|';
        }
        else{
            bullet_icon='-';
        }
           if(this->reload<=0){
            this->reload=enemy_reload;
        Projectile *new_proj = new Projectile(dir,this->getx(),this->gety(), bullet_icon);
        projectile.push_back(new_proj); 
    }
    else{
        this->reload--;
    }
     }
     //per movimento proiettili e check di colpito o out of range
     void checkProjectile(Board board_win, Characters hero);
     //va a una tua stessa linea o colonna per spararti e spara
    void ChooseDirection(Board board_win, Characters &hero) override
    {
         int distancex, distancey;
        distancex = this->x - hero.getx();
        distancey = this->y - hero.gety();
         if(hasLos(board_win, hero, this->y, this->x) && abs(distancex) < sight_range && abs(distancey) < sight_range){
            this->mem=enemy_memory;
            }
        if (this->mem>0)
        {
        if(distancey==0){
            if(distancex>0){
                createProjectile(sx);
            }
            else{
                createProjectile(dx);
            }
        }
        else{
            if(distancex==0){
                if(distancey>0){
                    createProjectile(up);
                }
                else{
                    createProjectile(down);
                }
            }
            else{

            if (abs(distancex) < abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                }
                else
                {
                    setDirection(sx);
                }
            }
            else
            {
                if (abs(distancex) > abs(distancey))
                {
                    if (distancey < 0)
                    {
                        setDirection(down);
                    }
                    else
                    {
                        setDirection(up);
                    }
                }
            }
        }
            }
        }
         this->mem--;
    }
};