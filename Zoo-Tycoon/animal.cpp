#include <iostream>
#include <string>
#include <cstdlib>
#include "./animal.h"
using namespace std;

Animal::Animal() {
	age = 0;
	cost = 0;
	num_babies = 0;
	base_food = 40;
	revenue = 0;
	animal_type = "yeet";
}

Animal::Animal(int x) {
	age = x;
}

Animal::~Animal() {
}

string Animal::getAnimalType() {
	return animal_type;
}

int Animal::get_Age() {
	return age;
}
float Animal::get_cost() {
	return cost;
}
int Animal::get_num_babies() {
	return num_babies;
}
float Animal::get_Base_food() {
	return base_food;
}
float Animal::get_revenue() {
	return revenue;
}
void Animal::age_week() {
	age++;
}
