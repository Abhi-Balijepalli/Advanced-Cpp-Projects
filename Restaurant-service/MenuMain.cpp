#include <iostream>
#include <string>
#include "./header.h"
#include "./header2.h"
#include "./header3.h"
#include <fstream>

using std::cout;
using std::string;
/******************
 * Program: default constructor
 * Descrition : constructs the variables
 *****************/
Menu::Menu() {
	num_pizzas = 0;
	thePizzas = NULL;
	//cout << "menu constructor was called " << endl;
}
/******************
 * Program: destructor
 * Descrition : deals with memory leaks
 *****************/
Menu::~Menu() {
	delete [] thePizzas;
	//cout << "menu destructor was caleed " << endl;
}
/******************
 * Program: copy constructor
 * Descrition : copys the dublicate object
 *****************/
Menu::Menu(const Menu &copyMenu) {
	num_pizzas = copyMenu.num_pizzas;
	thePizzas = new Pizza [num_pizzas];
	for(int i = 0; i < num_pizzas; i++) {
		thePizzas[i] = copyMenu.thePizzas[i];
	}
	//cout << "menu Copy constructor was called" << endl;
}
/******************
 * Program: assignment operator
 * Descrition : assigns to the object
 *****************/
const Menu &Menu::operator = (const Menu &copyMenu) {
	delete [] thePizzas;
	thePizzas = new Pizza [num_pizzas];
	for(int i = 0; i < num_pizzas; i++) {
		thePizzas[i] = copyMenu.thePizzas[i];
	}
	//cout << "menu assignmentOperator was called" << endl;
}

void Menu::set_numPizza(int num) {
	this->num_pizzas = num;

}
int Menu::set_numPizza() {
	return num_pizzas;
}
