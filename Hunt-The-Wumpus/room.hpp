#ifndef ROOM_HPP
#define ROOM_HPP
#include<iostream>
#include<vector>
#include"wumpus.hpp"
#include"bat.hpp"
#include"gold.hpp"
#include"pit.hpp"

class Room{
	
	private:
		int finder;
		Event *event;	
	public:
		Room();
		void set_Finder(int finder);
		void set_wumpus();
		void set_bat();
		void set_pit();
		void set_gold();

		int get_Finder();
		void encounterPrint();
		void printPercept();
	
		~Room();
};

#endif
