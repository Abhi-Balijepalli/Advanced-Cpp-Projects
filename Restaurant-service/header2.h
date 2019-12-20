#include <iostream>
#include <string>
#include <fstream>
//#include "./header3.h"
#include "./header.h"
using namespace std;
#ifndef HEADER2_H
#define HEADER2_H
class Menu {
	private:
		int num_pizzas;
		Pizza* thePizzas;
	public:
		Menu();
		~Menu();
		Menu(const Menu &);
		const Menu &operator = (const Menu &);
		Menu search_pizza_by_cost(int upper_bound, string size);
		Menu search_pizza_by_ingredients_to_include(string *ingredients, int num_ingredients);
		Menu search_pizza_by_ingredients_to_exclude(string *ingredients, int num_ingredients);

		void set_numPizza(int num);
		int set_numPizza();
		void add_to_menu(Pizza pizza_to_add);
		void remove_from_menu(int index_of_pizza_on_menu);
};         
#endif
