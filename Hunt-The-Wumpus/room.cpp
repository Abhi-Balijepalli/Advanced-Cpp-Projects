/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description:
******************************************************/
#include"room.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

Room::Room(){
	finder = 0;
	event = NULL;
}

void Room::set_Finder(int finder){
	this -> finder = finder;
}

int Room::get_Finder(){
	return finder;
}

void Room::set_wumpus(){
	if(event != NULL){
		delete event;
	}
	event = new Wumpus;
}

void Room::set_gold(){
        if(event != NULL){
                delete event;
        }
        event = new Gold;
}

void Room::set_pit(){
        if(event != NULL){
                delete event;
        }
        event = new Pit;
}

void Room::set_bat(){
        if(event != NULL){
                delete event;
        }
        event = new Bat;
}
// prints out the encounter part when there is a event item
void Room::encounterPrint(){
	cout << (event->encounter()) << endl;
}

// prints out the encounter part when there is a event item
void Room::printPercept(){
	cout << (event->percept()) << endl;
}
Room::~Room(){
	delete event;
}
