// Rogue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <curses.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "Object.h"
#include "Player.h"

//TODO: Figure out how to load properties from an xml file eg. Peach: Sticky
//TODO: Allow Plates to be placed on the screen
//TODO: Populate Plates with random detritus
int main(){

	
	//Intialize System
	int ch;
	//Player p;
	initscr();			
	keypad(stdscr, TRUE);
	noecho();

	
	//Main Game Loop
	while (true) {
		
		ch = getch();
		werase(stdscr);
		for (int i = 0; i < 9; i++) {
			move(6, 6 + i);
			printw("X");
		}
		//p.move(ch);
		refresh();
		
	
	}
	
}
