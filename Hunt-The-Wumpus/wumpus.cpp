/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description:
******************************************************/
#include"wumpus.hpp"
#include<string>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Wumpus::Wumpus(){
	set_name_event();
}

void Wumpus::set_name_event(){

	name_event = "Wumpus";
}
// polymorphic behaviour
string Wumpus::encounter(){
	string y = "F, the wumpus ate you or somthing, basically you died." ;
	return y;
}

// polymorphic behaviour
string Wumpus::percept(){
	string x = "Something smells terrible here...";
	return x;
}
