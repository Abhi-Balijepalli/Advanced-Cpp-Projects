/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description:
******************************************************/
#include"pit.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Pit::Pit(){
	set_name_event();
}

void Pit::set_name_event(){

	name_event = "Pit";
}

string Pit::encounter(){
	string y = "F, you fell in a pit and died";
	return y;
}
string Pit::percept(){
	string x = "You feel a cool breeze";
	return x;
}
