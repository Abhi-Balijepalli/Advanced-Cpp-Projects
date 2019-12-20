
#include <iostream>
#include <string>
#include "./sea_otter.h"
/***************** 
 * Name: seaotter()
 * Description: constructor
 ****************/
Seaotter::Seaotter() : Animal() {
	cost = 5000;
	base_food = 40;
	revenue = cost * 0.5;
	animal_type = "Sea Otter";

}
/********************* 
 * Name: seaotter(int )
 * Description: constructor with a int
 ********************/
Seaotter::Seaotter(int ) : Animal() {
	cost = 5000;
	base_food = 40;
	revenue = cost * 0.25;
	animal_type = "Sea Otter";
	age = 0;
}
