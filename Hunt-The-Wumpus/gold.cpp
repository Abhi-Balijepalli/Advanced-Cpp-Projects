/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description:
******************************************************/
#include"gold.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Gold::Gold(){
	set_name_event();
}

void Gold::set_name_event(){
	name_event = "Gold";
}

string Gold::encounter(){
	string y = "wow, you found gold";
	return y;
}
string Gold::percept(){
	string x = "You see a glimmer nearby";
	return x;
}
