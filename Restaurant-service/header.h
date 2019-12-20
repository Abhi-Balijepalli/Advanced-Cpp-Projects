#include <iostream>
#include <string>
#include <fstream>
//#include "./header2.h"
//#include "./header3.h"
using namespace std;

#ifndef HEADER_H
#define HEADER_H

struct employee {
	int id;
	string password;
	string first_name;
	string last_name;
//	string num_employees;
};

struct hour {
	string day;
	string open_hour;
	string close_hour;
//	string num_hours;
};               
void verification(employee*,int);
void password_check(employee *, int, int);
void error_handle(string *temp);

class Pizza {
	private:
		const string Name;
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string *ingredients;
	public:
	// include accessor functions and mutator functions for each private member	
		Pizza();
		~Pizza();
		Pizza(const Pizza &);
		const Pizza &operator = (const Pizza&);
		void get_info_pizza(fstream &);
		void set_name(string name);
		string get_name();
		void set_num_ingredients(int);
		int get_num_ingredients();
		//void set_ingredients(int amount, string ingredient);	
		void set_small_cost(int);
		int get_small_cost(int);
		void set_medium_cost(int );
		int get_medium_cost();
		void set_large_cost(int );
		void get_large_cost();
};                                                      
                                                                                                    
#endif






