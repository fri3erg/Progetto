#pragma once 

#include "GeneralTemplate.hpp"  //room_templates/
#include "Hero.hpp"
#include <cstdlib>
#include <vector>

using namespace std;

#define NUMBER_OF_ROOMS 29

class Room {
private:
    int room_template_number;
    General_template *room_template;
    void decideIfDoors();
    Room* findRoom(vector<Room*> room_index, int y, int x, Direction dir);

    int randomRoomNumber(); 
    void initializeRoomTemplate(int template_num, int n,Board &game_board);

    void lockNorthDoor();
    void lockSouthDoor();
    void lockWestDoor();
    void lockEstDoor();
    
    void drawProjectiles(Board &board);
    void drawEnemies(Board &board);
    void drawArtifact(Board &board);
    void drawWalls(Board &board);
    void drawDoors(Board &board);

    //funzioni per i nemici
    void removeEnemy(int pos);
    void addEnemy(pEn enemy);
    //void damageEnemy(int damage);
    //void healEnemy(int healing);

public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;
    bool has_north_door, has_south_door, has_west_door, has_est_door;

    Room(Board &game_board);    //costrutture stanza di partenza

    Room(int y, int x, vector<Room*> room_index,int n,Board &game_board);   //costruttore stanza generica

    void drawRoom(Board &board);

    void moveEnemies(Board &board, Hero &hero);

    bool isClear();

    void unlockDoor(int y, int x);

    void removeArtifact(int pos);

}; typedef Room* prm;

