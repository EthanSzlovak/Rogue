#include "curses.h"
WINDOW* create_newwin(int height, int width, int starty, int startx, char c);
void destroy_win(WINDOW* local_win);

struct DOOD {
	int xLoc_, yLoc_;
	int counter_;
	int maxCounter_;
	bool asc = false;
	WINDOW* thisDOOD;
	DOOD(int x, int y, int max) {
		xLoc_ = x;
		maxCounter_ = max;
		yLoc_ = y;
		counter_ = 0;
		thisDOOD = create_newwin(1, 1, x, y, '☺');

	}
	void update() {
		if (counter_ == maxCounter_) {
			asc = false;
		}if (counter_ == 0) {
			asc = true;
		}

		if (asc) {
			counter_++;
			xLoc_++;
		}else {
			counter_--;
			xLoc_--;
		}
		
		destroy_win(thisDOOD);
		create_newwin(1, 1, xLoc_, yLoc_, '☺');
		
	}
};

DOOD* n[5];

int main(int argc, char* argv[])
{
	WINDOW* my_win;
	WINDOW* main_win;


	int startx, starty, width, height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	DOOD n(10, 10, 5);
	height = 1;
	width = 1;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx, '@');

	while ((ch = getch()) != KEY_F(1))
	{
		switch (ch){
		case KEY_LEFT:
			destroy_win(my_win);
			my_win = create_newwin(height, width, starty, --startx,'@');
			
			break;
		case KEY_RIGHT:
			destroy_win(my_win);
			my_win = create_newwin(height, width, starty, ++startx, '@');
			
			break;
		case KEY_UP:
			destroy_win(my_win);
			my_win = create_newwin(height, width, --starty, startx, '@');
			
			break;
		case KEY_DOWN:
			destroy_win(my_win);
			my_win = create_newwin(height, width, ++starty, startx, '@');
			
			break;
		}
		n.update();
	}

	endwin();			/* End curses mode		  */
	return 0;
}

WINDOW* create_newwin(int height, int width, int starty, int startx, char c)
{
	WINDOW* local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wmove(local_win, 0,0);
	wprintw(local_win, &c);

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