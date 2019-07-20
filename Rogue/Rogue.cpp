#include <vector>
#include <cstring>

#include "curses.h"
#include "iObject.h"
#include "Player.h"
#include "Chest.h"
#include "Monster.h"

//Using Variables
using Rogue::iObject;
using std::vector;

//Window Function Definitions
WINDOW* updateInventoryWindow(WINDOW* w);
WINDOW* create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW* local_win);

//Immediately Instantiated Variables
Chest c("Treasure", 4, 5);
Chest d("Gold", 6, 5);
Player p(0, 0);

//Enemylisting
/*vector<Monster> monsterList{ Monster(5,5), Monster(10, 5) };
vector<Object*> abstractEnemyList{ &monsterList[0], &monsterList[1] }*/;
Monster m1(10, 5, 'M');
Monster m2(5, 19, '&');

iObject* abstract_m1 = &m1;
iObject* abstract_m2 = &m2;

int main(int argc, char* argv[]){
	WINDOW* mainGameWindow;
	WINDOW* inventoryWindow;
	int ch;

	//Start Curses Mode
	initscr();			
	cbreak();		

	//Allow Function Keys
	keypad(stdscr, TRUE);

	//Set Start Variables for Main Window
	mainGameWindow = create_newwin(20, 40, 5, 1);

	//Initialize Inventory Window
	inventoryWindow = newwin(20, 40, 5, 55);
	box(inventoryWindow, 0, 0);
	wprintw(inventoryWindow, "Inventory");
	
	refresh();
	wrefresh(mainGameWindow);
	wrefresh(inventoryWindow);
	printw("Press F1 to exit");

	//TODO: Implement Enemy Creatures
	

	while ((ch = getch()) != KEY_F(1)){
		//Player move loop
		switch (ch){
		case KEY_LEFT:
			p.xLoc()--;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, 5, 1);
			break;
		case KEY_RIGHT:
			p.xLoc()++;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, 5, 1);
			break;
		case KEY_UP:
			p.yLoc()--;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, 5, 1);
			break;
		case KEY_DOWN:
			p.yLoc()++;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, 5, 1);
			break;
		}

		
		updateInventoryWindow(inventoryWindow);
		
		

	}
	
	endwin();			/* End curses mode		  */
	p.move();
	return 0;
}


//Update inventory Window
WINDOW* updateInventoryWindow(WINDOW* w) {
	//Get all items in the player inventory
	for (int i = 0; i < inventory.size(); ++i) {
		wmove(w, i + 1, 1);
		wprintw(w, inventory.at(i).c_str());
	}

	//Redraw the Window
	wrefresh(w);

	return w;
}
WINDOW* create_newwin(int height, int width, int starty, int startx){
	WINDOW* local_win;

	// used to maintain tick speed
	static int alternation = 0;

	local_win = newwin(height, width, starty, startx);

	//Draw box of default characters
	box(local_win, 0, 0);

	//Print everything in the main window
	wprintw(local_win, "Main Window");
	wmove(local_win, 0, 0);	

	//Update Chests
	c.draw(local_win);
	d.draw(local_win);
	
	//Update Player
	p.draw(local_win);

	//Update Monster with Player's Coordinates
	if (alternation % 2 == 0)
	{
		abstract_m1->move(p.xLoc(), p.yLoc());
		abstract_m2->move(p.xLoc(), p.yLoc());
	}

	//Display Monsters
	abstract_m1->draw(local_win);
	abstract_m2->draw(local_win);

	//Update Chests
	c.updateState(local_win);
	d.updateState(local_win);

	//show Box
	wrefresh(local_win);		/* Show that box 		*/

	// used to maintain tick speed
	++alternation;

	return local_win;
}

void destroy_win(WINDOW* local_win)
{
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners
	 * and so an ugly remnant of window.
	 */
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}