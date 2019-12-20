/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description: game.hpp class that deals with making the function declarations in a .hpp  
******************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include<iostream>
#include<cstdlib>
#include<vector>
#include"event.hpp"
#include"room.hpp"
#include"gold.hpp"
#include"bat.hpp"
#include"wumpus.hpp"
#include"pit.hpp"
//#include<ctime>

class Game{
	private: 
		vector<vector<Room*>>map;
		int sizeMap;
		int direction;
		int xPlane;
		int yPlane;	
		int identifier;
		int targetX;
		int targetY;
		int eventArr[7];
		int pitUno;
		int pitDos;
		int batUno;
		int batDos;
		int wumpusUno;
		int ladder;
		int gold_1;
		int arrow;
		bool wumpusStatus;
		int goldMake;
		int spot;
	public:
		Game();
		Game(int size);
		int choose_direction();
		void randGen();
		bool area_of_cave(int r, int c);	
		int win();	
		void area_check();
		int event_check();			
		void start_game();	
		void print_map();
		void debugDisplay();	
		void area_1();
		void area_2();
		void area_3();
		void area_4();
		void area_5();
		int shootingArrow();	
		void wumpus_move();		
		~Game();
};

#endif
