#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class Animal {
	protected:
		int age;
		float cost;
		int num_babies;
		float base_food;
		float revenue;
		string animal_type;
	public:
		Animal();
		Animal(int);
		~Animal();
		string getAnimalType();
		int get_Age();
		float get_cost();
		int get_num_babies();
		float get_Base_food();
		float get_revenue();
		void age_week();
};
#endif
