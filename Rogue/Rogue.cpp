#include "curses.h"
#include "Object.h"
#include "Player.h"
#include <vector>
WINDOW* create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW* local_win);

using Rogue::Object;
using std::vector;
Player p(0, 0);
vector<Object> enemyList;
std::string* inventory = new std::string[5];
int main(int argc, char* argv[]){
	WINDOW* mainGameWindow;
	WINDOW* inventoryWindow;
	int startx, starty, width, height;
	int ch;
	//Start Curses Mode
	initscr();			
	cbreak();			
	//Allow Function Keys
	keypad(stdscr, TRUE);

	//Set Start Variables for Main Window
	starty = 5;
	startx = 0;

	mainGameWindow = create_newwin(20, 40, starty, startx);
	inventoryWindow = newwin(20, 40, 5, 55);
	box(inventoryWindow, 0, 0);
	wprintw(inventoryWindow, "TESTINT");


	wrefresh(inventoryWindow);
	refresh();
	wrefresh(inventoryWindow);
	printw("Press F1 to exit");

	//TODO: Implement Enemy Creatures
	for (int i = 0; i < 5; ++i) {


		//enemyList.insert()
	}
	

	while ((ch = getch()) != KEY_F(1)){
		switch (ch){
		case KEY_LEFT:
			p.xLoc()--;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, starty, startx);
			break;
		case KEY_RIGHT:
			p.xLoc()++;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, starty, startx);
			break;
		case KEY_UP:
			p.yLoc()--;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, starty, startx);
			break;
		case KEY_DOWN:
			p.yLoc()++;
			destroy_win(mainGameWindow);
			mainGameWindow = create_newwin(20, 40, starty, startx);
			break;
		}
	}
	
	endwin();			/* End curses mode		  */
	p.move();
	delete[] inventory;
	return 0;
}

WINDOW* create_newwin(int height, int width, int starty, int startx){
	WINDOW* local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/


	wprintw(local_win, "TEST");
	wmove(local_win, 0, 0);	
	p.draw(local_win);
	wrefresh(local_win);		/* Show that box 		*/

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