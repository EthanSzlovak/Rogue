// Rogue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <curses.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "Object.h"
#include "Player.h"

//TODO:
//Use an action type thing for different speeds, eg one guy can take multiple 'turns' per turn. Essentially, how many actions that things can do per turn?
//eg, Wendigo has 3 moves per turn?
int main(){
	int ch;
	Player p;
	
	initscr();			
	keypad(stdscr, TRUE);
	noecho();
	
	
	
	
	
	while (true) {
		
		ch = getch();
		werase(stdscr);
		for (int i = 0; i < 9; i++) {
			move(6, 6 + i);
			printw("X");
		}
		
		p.move(ch);
		


		refresh();
		
	
	}
	
}
