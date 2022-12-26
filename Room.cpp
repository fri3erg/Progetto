#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
Room::Room() {
    this->y = 0; this->x = 0;
    this->north = NULL; 
    this->south = NULL; 
    this->west = NULL; 
    this->est = NULL; 
    initializeRoomTemplate(0);
    this->room_template_number = 0;
}

Room::Room(int y, int x, vector<Room*> room_index) {//int room_template) {
    this->y = y; this->x = x;
    this->north = findRoom(room_index, y+1, x);
    this->south = findRoom(room_index, y-1, x);
    this->west = findRoom(room_index, y, x-1);
	this->est = findRoom(room_index, y, x+1);
    int n = rand()%9+1;
    this->room_template_number = n;
    initializeRoomTemplate(n);
}

void Room::initializeRoomTemplate(int template_num) {
    switch (template_num)
    {
    case 0:
        this->room_template = new Template_0i();
        break;
    case 1:
        this->room_template = new Template_1();
        break;
    case 2:
        this->room_template = new Template_2i();
        break;
    case 3:
        this->room_template = new Template_3i();
        break;
    case 4:
        this->room_template = new Template_4i();
        break;
    case 5:
        this->room_template = new Template_5i();
        break;
    case 6:
        this->room_template = new Template_6();
        break;
    case 7:
        this->room_template = new Template_7();
        break; 
    case 8:
        this->room_template = new Template_8();
        break; 
    case 9:
        this->room_template = new Template_9();
        break; 
    default:
        this->room_template = new Template_0();
        break;
    }
}

Room* Room::findRoom(vector<Room*> room_index, int y, int x){
    int n = -1;
		for(int i = 0; i < room_index.size(); i++)
		{
			if(room_index[i]->y == y && room_index[i]->x == x)
			{
				n = i; 
				break;	
			}
		}
	if(n < 0) return NULL;
	else return room_index[n]; 
}

void Room::drawRoom(Board &board) {
    drawEnemies(board);
    drawWalls(board);
    drawDoors(board);
    drawProjectiles(board);
}

void Room::moveEnemies(Board &board, Hero &hero) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
         this->room_template->enemies[i]->chooseDirection(board, hero);
         this->room_template->enemies[i]->checkProjectile(board, hero);
       if(this->room_template->enemies[i]->checkCollision(board)) {
            this->room_template->enemies[i]->moveCharacter();
            
        }
    }
}

bool Room::isClear() {
    //return room_template->enemies_num == 0;    //per il testing è disattivata 
    return 1;
}


// funzioni private

void Room::drawProjectiles(Board &board){
for(int j = 0; j < room_template->enemies_num; j++) { 
    for (int i = 0; i < room_template->enemies[j]->projectile.size(); i++)
		{
            board.add(*room_template->enemies[j]->projectile[i]);
        }
        }
}

void Room::drawEnemies(Board &board) {
    for(int i = 0; i < room_template->enemies_num; i++) {    
        board.add(*room_template->enemies[i]);
       // board.addAt(room_template->enemies[i]->gety(), room_template->enemies[i]->getx(), room_template->enemies[i]->getIcon());
    }
   // wrefresh(board);
}

void Room::drawWalls(Board &board) {
    for(int i = 0; i < room_template->walls_num; i++) {    
        board.add(room_template->walls[i]);
    }
}

void Room::drawDoors(Board &board) {
    for(int i = 0; i < room_template->doors_num; i++) {    
        board.add(room_template->doors[i]);
    }
}


void Room::removeEnemy(int pos) {
    pEn temp = room_template->enemies[pos];
    room_template->enemies[pos] = room_template->enemies[room_template->enemies_num-1];
    room_template->enemies[room_template->enemies_num-1] = temp;
    room_template->enemies_num--;
}

void Room::addEnemy(pEn enemy) {
    room_template->enemies_num++;
    room_template->enemies[room_template->enemies_num-1] = enemy;
}