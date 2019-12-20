#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "./header.h"
#include "./header2.h"
#include "./header3.h"
using std::cout;
using std::string;

//constructors
/******************************************************
** Program: default constructor
** Author: stickZ
** Date: 04/29/2019
** Description: constructors the variables in the pizza class  
** Input: N/A
** Output: N/A
******************************************************/
Pizza::Pizza() {
	name = "";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
	//cout << "default constructor was called" << endl;
}
/******************************************************
** Program: deconstructor
** Author: stickZ
** Date: 04/29/2019
** Description: deletes the ingredients array  
** Input: N/A
** Output: N/A
******************************************************/
Pizza::~Pizza() {
	delete [] ingredients;
	//cout << "destructor was called" << endl;
}
/******************************************************
** Program: copy constructor
** Author: stickZ
** Date: 04/29/2019
** Description: copy constructor for pizza class  
** Input: N/A
** Output: N/A
******************************************************/
Pizza::Pizza(const Pizza &copyPizza) {
	name = copyPizza.name;
	small_cost = copyPizza.small_cost;
	medium_cost = copyPizza.medium_cost;
	large_cost = copyPizza.large_cost;
	num_ingredients = copyPizza.num_ingredients;
	ingredients = new string [num_ingredients];
	for(int i =0; i < num_ingredients; i++) {
		ingredients[i] = copyPizza.ingredients[i];
	}
	//cout << "constructor was called" << endl;            
}
/******************************************************
** Program: assignment operator
** Author: stickZ
** Date: 04/29/2019
** Description: assigns object to another copy object  
** Input: N/A
** Output: N/A
******************************************************/
const Pizza &Pizza::operator = (const Pizza &copyPizza) {
	delete [] ingredients;
	name = copyPizza.name;
	small_cost = copyPizza.small_cost;
	medium_cost = copyPizza.medium_cost;
	large_cost = copyPizza.large_cost;
	num_ingredients = copyPizza.num_ingredients;
	ingredients = new string [num_ingredients];
	for(int i =0; i < num_ingredients; i++) {
		ingredients[i] = copyPizza.ingredients[i];
	}
	//cout << "assignment operator was called was called" << endl;   
}
/*
void Pizza::get_info_pizza(fstream &file) {
	file.open("menu.txt");
	for(int i = 0; i < 



} */
/******************************************************
** Program: set_name()
** Author: stickZ
** Date: 04/29/2019
** Description: setter function for name  
** Input: N/A
** Output: N/A
******************************************************/
void Pizza::set_name(string name) {
	this->name = name; // accessors
}
/******************************************************
** Program: get_name()
** Author: stickZ
** Date: 04/29/2019
** Description: getter function for name  
** Input: N/A
** Output: N/A
******************************************************/
string Pizza::get_name() {
	return name; //mutators
}
/******************************************************
** Program: set_num_ingredients
** Author: stickZ
** Date: 04/29/2019
** Description: setter function for num_ingredients  
** Input: N/A
** Output: N/A
******************************************************/
void Pizza::set_num_ingredients(int num) {
	this->num_ingredients = num; //accessors
}
/******************************************************
** Program: get_num_ingredients()
** Author: stickZ
** Date: 04/29/2019
** Description: getter function for ingredients  
** Input: N/A
** Output: N/A
******************************************************/
int Pizza::get_num_ingredients() {
	return num_ingredients; // mutators
}
/******************************************************
** Program: set_small_cost()
** Author: stickZ
** Date: 04/29/2019
** Description: setter function for get_small_cost  
** Input: N/A
** Output: N/A
******************************************************/
void Pizza::set_small_cost(int small_cost) {
	this->small_cost = small_cost; //accessors
}
/******************************************************
** Program: get_small_cost()
** Author: stickZ
** Date: 04/29/2019
** Description:  
** Input: N/A
** Output: N/A
******************************************************/
int Pizza::get_small_cost(int small_cost) {
	return small_cost; //mutators
}
/******************************************************
** Program: set_medium_cost()
** Author: stickZ
** Date: 04/29/2019
** Description: setter function for set_medium_cost  
** Input: N/A
** Output: N/A
******************************************************/
void Pizza::set_medium_cost(int medium_cost) {
	this->medium_cost = medium_cost; //accessors
}
/******************************************************
** Program: get_medium_cost()
** Author: stickZ
** Date: 04/29/2019
** Description: getter function for medium cost  
** Input: N/A
** Output: N/A
******************************************************/
int Pizza::get_medium_cost(){
	return medium_cost; //mutators
}
/******************************************************
** Program: set_large_cost()
** Author: stickZ
** Date: 04/29/2019
** Description: setter function for large cost  
** Input: N/A
** Output: N/A
******************************************************/
void Pizza::set_large_cost(int large_cost) {
	this->large_cost = large_cost; //accessors
}
/******************************************************
** Program: get_large_cost()
** Author: stickZ
** Date: 04/29/2019
** Description: getter function for large cost  
** Input: N/A
** Output:N/A
******************************************************/
void Pizza::get_large_cost() {
	this-> large_cost; //mutators
}












