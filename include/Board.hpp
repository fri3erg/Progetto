#pragma once

#include <cstdlib>      //per i numeri random
#include <time.h>
#include "Drawable.hpp"
#include "Time.hpp"

#define BOSS_PAIR 1
#define ENEMY_PAIR 2
#define ARTIFACT_PAIR 3
const int BOARD_DIM = 25;					//prima era 17
const int BOARD_ROWS = BOARD_DIM;
const int BOARD_COLS = BOARD_DIM * 2.7;//2.5;
const int difficultyRate=40;


class Board
{
protected:
	int difficulty;
	WINDOW *board_win;
	int timeout;
	bool taken[BOARD_COLS][BOARD_ROWS];
public:
	Board();
	Board(int height, int width, int speed);
	Board(int height, int width, int starty, int startx, int speed);

	void initialize();
	void setTaken(int x, int y,bool set);
	bool getTaken(int x, int y);
	void clearTaken();
    void add(Drawable &drawable);
    void add_A(Drawable &drawable);
    void add_E(Drawable &drawable);
	void add_B(Drawable &drawable);
	void remove(Drawable &drawable);
	void addAt(int y, int x, chtype ch);	
	void print(const char* str);
	void print(chtype str);
	int getDifficulty();
	void setDifficulty(int diff);
	void refreshDifficulty(int score);


    chtype getInput();
	chtype getCharAt(int y, int x);
    void getEmptyCoordinates(int &y, int &x);

    void setTimeout(int timeout);
    int getTimeout();

    void clear ();
	void refreshBoard();
	void addBorder();
};