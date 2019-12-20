#include <iostream>
#include <string>
#include "./meerkat.h"
using namespace std;
/************ 
 * Name: Meerkat()
 * Description: default constructor
 **************/
Meerkat::Meerkat() : Animal() {
	cost = 500;
	num_babies = 5;
	base_food = 40;
	revenue = cost * 0.5;
	animal_type = "Meerkat";
}
/******************** 
 * Name: Meerkat(int )
 * Description: constructor with a arg value
 ********************/
Meerkat::Meerkat(int x) : Animal() {
	cost = 500;
	num_babies = 5;
	base_food = 40;
	revenue = cost * 0.1;
	animal_type = "Meerkat";
	age = 0;
}


