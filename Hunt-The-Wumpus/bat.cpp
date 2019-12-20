#include"bat.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Bat::Bat(){
	set_name_event();
}
void Bat::set_name_event(){
	name_event = "Super Bats";
}

string Bat::encounter(){
	string y = "The bat has taken you into a random room in the cave";
	return y;
}
string Bat::percept(){
	string x = "You hear the sound of wings flapping.";
	return x;
}
