#include "Characters.hpp"

Characters::Characters(int y, int x, chtype ch):Drawable(y,x,ch){
		setDirection(def);
	}
	void Characters::setDirection(Direction newdir)
	{
		cur_direction = newdir;
	}
	// move
	Direction Characters:: getDirection()
	{
		return cur_direction;
	}
	void Characters:: moveCharacter()
	{
		switch (cur_direction)
		{
		case down:
			y++;
			break;
		case up:
			y--;
			break;
		case sx:
			x--;
			break;
		case dx:
			x++;
			break;
		default:
			break;
		}
	}
	// collisione
	bool Characters::checkCollision(Board board_win)
	{
		int offsety = 0, offsetx = 0;
		if (cur_direction == up || cur_direction == down)
		{
			// offset per row e col per collisione
			offsety = cur_direction / 2;
		}
		else
		{
			if (cur_direction == dx || cur_direction == sx)
			{
				offsetx = cur_direction;
			}
		}
		switch (board_win.getCharAt(y + offsety, x + offsetx))
		{
		case ' ':
		case 'F':
		case 'H':
		case 'O':		//cambia stanza
			return true;
			break;
		case 'Q':
		return false;
			// porta chiuisa:
			// controlla se il giocatore ha una chiave
			// se ne ha, ne toglie una e cambia il carattere di tutta la porta
			// e fa manageDoor();
			break;

		default:
			return false;
			break;
		}
		return false;
	}