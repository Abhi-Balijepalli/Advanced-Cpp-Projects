#include <iostream>
#include <string>
#include "./monkeys.h"
/* 
 * Name: constructor
 * Description: default constructor
 */
Monkeys::Monkeys() : Animal() {
	cost = 15000;
	num_babies = 1;
	base_food = 40;
	revenue = cost * 0.1;
	animal_type = "Monkey";
}
/* 
 * Name: Constructor with argument value
 * Description: this will construct with age
 */
Monkeys::Monkeys(int x) : Animal() {
	cost = 15000;
	num_babies = 1;
	base_food = 40;
	revenue = cost * 0.1;
	animal_type = "Monkey";
	age = 0;
}
