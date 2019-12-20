#include <iostream>
#include <string>
#include <fstream>
#include "./header2.h"
#include "./header.h"
using namespace std;

#ifndef HEADER3_H
#define HEADER3_H
class Restaurant {
	private:
		Menu menu;
		int num_employees;
		employee* employees;
		hour* week;
		int num_days;
		string name;
		string phone;
		string address;
	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Restaurant &);
		const Restaurant &operator = (const Restaurant &);
		void load_data_employees();
		employee* get_employees();
		void identificationEmp(fstream &, int);
		void identificationHour(fstream &, int);
 		bool login(string id, string password);
		void employee_view();
		void customer_view();
		void boonk_login();
		int get_num_employees();
		hour* get_hours();
		int get_days();
		string get_address();
		string get_phone();
		string get_name ();
		void view_menu();
		void view_hours();
		void view_address();
		void view_phone();
		void search_menu_by_price();
		void search_by_ingredients();
		void place_order(Pizza* selection);
		void change_hours();
		void add_to_menu();
		void remove_from_menu();
		void view_orders();
		void remove_orders();
};         
#endif
