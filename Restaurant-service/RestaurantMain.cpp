#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "./header.h"
#include "./header3.h"
#include "./header2.h"

using std::cout;
using std::string;

/******************************************************
** Program: default constructor
** Author: stickZ
** Date: 04/29/2019
** Description: constructor  
** Input: all variables
** Output: N/A
******************************************************/
Restaurant::Restaurant() {
	employees = new employee[3];
	week = new hour[7];
	name = "";
	phone = "";
	address = "";
	num_employees = -1;
	num_days = 7;
	//cout << "default constructor was called for restaurant" << endl;
}

/******************************************************
** Program: deconstructor
** Author: stickZ
** Date: 04/16/2019
** Description:  deletes memomry on the heap
** Input: N/A
** Output: N/A
******************************************************/
Restaurant::~Restaurant() {
	delete [] employees;
	delete [] week;
}

/******************************************************
** Program: copy
** Author: stickZ
** Date: 04/29/2019
** Description: copy  
** Input: N/A
** Output: N/A
******************************************************/
Restaurant::Restaurant(const Restaurant &resCopy) {
	name = resCopy.name;
	phone = resCopy.phone;
	address = resCopy.address;
	week = new hour [num_days];
	employees = new employee[num_employees];
	//cout << "the assignment operator was created for restaurant" << endl;
}

/******************************************************
** Program: assignment operator
** Author: stickZ
** Date: 04/29/2019
** Description: assigns to the copy  
** Input: copy (const)
** Output: N/A
******************************************************/
const Restaurant &Restaurant::operator = (const Restaurant &resCopy) {
	delete [] week;
	delete [] employees;
	name = resCopy.name;
	phone = resCopy.phone;
	address = resCopy.address;
	week = new hour [num_days];
	employees = new employee[num_employees];
	//cout << "the assignment operator was created for restaurant" << endl;
}

/******************************************************
** Program: load_data_employees()
** Author: stickZ
** Date: 04/29/2019
** Description: load data and transfer the data to different sections
** Input: N/A
** Output: N/A
******************************************************/
void Restaurant::load_data_employees() {
	fstream empID;
	string line;
	empID.open("employee.txt");
	while(getline(empID,line)) {
		num_employees++;
	}	
	empID.close();
	empID.open("employees.txt");

	fstream hourID;
	hourID.open("restaurant_info.txt");
	
	do {
		cout << "hey, are you  an Employee (e) or Customer (c)" << endl;
		string input;
		getline(cin,input);
		if(input == "e") {
			identificationEmp(empID,num_employees);
			
			//employee_view();
			break;
		} else if (input == "c") {
			customer_view();
			//hourID.close();
			break;
		} else if (input == "quit") {
			exit(0);
		} else {
		}
	}while(true);
	//identificationHour(hourID,num_days);
}
/******************************************************
** Program: get_easaxmployees()
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: N/A
** Output: N/A
******************************************************/
employee* Restaurant::get_employees() {
	return employees;
}
/******************************************************
** Program: -
** Author: stickZ
** Date: 04/29/2019
** Description: assigns values to the employees array.  
** Input: empID, and num_employees
** Output: N/A
******************************************************/
void Restaurant::identificationEmp(fstream &empID, int num_employees) {
	empID.open("employee.txt");
	//cout << "amt of lines: " << amt << endl;
	string temp;
	for(int i =0; i < num_employees; i++) {
		getline(empID,temp,' ');
		employees[i].id = atoi(temp.c_str());
		//cout << "id: " << employees[i].id << endl;
		getline(empID,temp,' ');
		employees[i].password = temp;
		getline(empID,temp,' ');
		employees[i].first_name = temp;
		getline(empID,temp);
		employees[i].last_name = temp;
	}

	boonk_login();
	//employee_view();
}
/******************************************************
** Program: -
** Author: stickZ
** Date: 04/29/2019
** Description:  does the same thing as aboove, but for the week array
** Input: hourID, num_days
** Output: N/A
******************************************************/
void Restaurant::identificationHour(fstream &hourID, int num_days) {
	hourID.open("restaurant_info.txt");
	string temp;
	getline(hourID,temp);
	name = temp;
	//cout << name <<  endl;
	getline(hourID,temp);
	phone = temp;
	//cout << phone << endl;
	getline(hourID,temp);
	address = temp;
	//cout << address << temp;
	for(int i =0; i < 7; i++){
		hourID >> week[i].day;
		//cout << week[i].day << " " << endl;
		hourID >> week[i].open_hour;
		hourID >> week[i].close_hour;
	}
}
/******************************************************
** Program: -
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: n/a
** Output: n/a
******************************************************/
int Restaurant::get_num_employees() {
	return num_employees;
}

/******************************************************
** Program: -
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input:
** Output:
******************************************************/
int Restaurant::get_days() {
	return num_days;
}
/******************************************************
** Program: -
** Author: Your Name
** Date: 04/16/2019
** Description: deals with login issues  
** Input: id and password
** Output: the employee name
******************************************************/
bool Restaurant::login(string id, string password) {
	//employee r = get_employees()[2];
	for(int i = 0; i < num_employees; i++) {
		if(employees[i].id == (atoi(id.c_str()))){
			if(employees[i].password == password) {
				cout << "welcome " << employees[i].first_name << endl;
				return true;
			}
		}
	}
	return false;	
}
/******************************************************
** Program: -
** Author: stickz
** Date: 04/16/2019
** Description:  this is the error handling for login and password
** Input: n/a
** Output: n/a
******************************************************/
void Restaurant::boonk_login() {
	bool checker = false;
	string id;
	string pass;
	//cin.ignore();
	do {
		cout << "What is you ID (press q to exit) : ";
		getline(cin,id);
		if(id == "q") {
			break;
		}
		cout << "what is your password: ";
		getline(cin,pass);
		checker = login(id,pass);
		if(checker == true) {
			break;
		} else {
			cout << "this input in invalid. Try again " << endl;
		}
	}while(checker == false);
	employee_view();
}
/******************************************************
** Program: 
** Author: stickz
** Date: 04/29/2019
** Description: choose the options for employee  
** Input: 1 - 10
** Output: result chosen
******************************************************/
void Restaurant::employee_view() {	
	string option;
	do {
		cout << "1. Change hours" << endl;
		cout << "2. View Orders" << endl;
		cout << "3. Remove Order" << endl;
		cout << "4. Add Item to Menu " << endl;
		cout << "5. Remove Item from Menu " << endl;
		cout << "6. view Menu " << endl;
		cout << "7. view hours " << endl;
		cout << "8. view address" << endl;
		cout << "9. view phone" << endl;
		cout << "10. log out " << endl;
		getline(cin,option);
		if(atoi(option.c_str()) <= 10 && atoi(option.c_str()) > 0) {
			int boonk = atoi(option.c_str());
			if(boonk == 1) {
				cout << "sorry didn't do that " << endl;
			} else if (boonk == 2) {
				view_orders();
			} else if ( boonk == 3) {
				cout <<	"sorry didn't do that " << endl;
			} else if (boonk == 4) {
				cout << "sorry didn't do that " << endl;
			} else if (boonk == 5) {
				cout << "sorry didn't do that " << endl;
			} else if (boonk == 6) {
				view_menu();
			} else if (boonk == 7) {
				view_hours();
			} else if (boonk == 8) {
				view_address();
			} else if (boonk == 9) {
				view_phone();
			} else if (boonk == 10) {
				cout << "...logging you out..." << endl;
				load_data_employees();
			}
			else {
				cout << "invalid input " << endl;
			}
		} else { 
			cout << "invalid input" << endl;
		}	
	}while(true);
}
/******************************************************
** Program: 
** Author: stickz
** Date: 04/29/2019
** Description: choose the options for customer  
** Input: 1 - 8
** Output: result chosen
******************************************************/
void Restaurant::customer_view() {
string option;
	do {
		cout << "1. view menu" << endl;
		cout << "2. search by cost" << endl;
		cout << "3. search by ingredients" << endl;
		cout << "4. place order" << endl;
		cout << "5. view hours" << endl;
		cout << "6. view address " << endl;
		cout << "7. view phone" << endl;
		cout << "8. log out" << endl;
		getline(cin,option);
		if(atoi(option.c_str()) <= 10 && atoi(option.c_str()) > 0) {
			int boonk = atoi(option.c_str());
			if(boonk == 1) {
				view_menu();
				//cout << "sorry didn't do that " << endl;
			} else if (boonk == 2) {
				//view_orders();
				cout << "sorry didn't do that" << endl;
			} else if ( boonk == 3) {
				cout <<	"sorry didn't do that " << endl;
			} else if (boonk == 4) {
				cout << "sorry didn't do that " << endl;
			} else if (boonk == 5) {
				view_hours();
			} else if (boonk == 6) {
				view_address();
			} else if (boonk == 7) {
				view_phone();
			} else if (boonk == 8) {
				cout << "...logging you out..." << endl;
				load_data_employees();
			} else {
				cout << "invalid input try again " << endl;
			}
		} else { 
			cout << "invalid input try again" << endl;
		}	
	}while(true);
}


/******************************************************
** Program: get_phone()
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: N/A
** Output: N/A
******************************************************/
string Restaurant::get_phone() {
	return phone;
}
/******************************************************
** Program: get_name()
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: N/A
** Output: N/A
******************************************************/
string Restaurant::get_name () {
	return name;
}
/******************************************************
** Program: get_address()
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: N/A
** Output: N/A
******************************************************/
string Restaurant::get_address() {
	return address;
}
/******************************************************
** Program: view_order()
** Author: stickZ
** Date: 04/29/2019
** Description: view orders  
** Input: N/A
** Output: N/A
******************************************************/
void Restaurant::view_orders() {
	
}
/******************************************************
** Program: view_phone()
** Author: stickZ
** Date: 04/29/2019
** Description: view phone number 
** Input: N/A
** Output: N/A
******************************************************/
void Restaurant::view_phone() {
	//phone = "(555) 543-8765";
	string phoneNum = get_phone();
	cout << "the phone number of the restaurant is: " << "(555) 543-8765" << endl;
}
/******************************************************
** Program: view_address()
** Author: stickZ
** Date: 04/29/2019
** Description: prints address  
** Input: N/A
** Output: N/A
******************************************************/
void Restaurant::view_address() {
	string add = get_address();
	cout << "the address of the restaurant is: " << add << endl;
}
void Restaurant::view_menu() {
	cout << "pizzas: " << endl;
	cout << "The_Bent 21 25 30 6 Cheese Pepperoni American Bacon Olivies Mushroom" << endl;
	cout << "Corvegas 12 23 28 5 Pesto Pepperoni Mozzarella Roasted_Red_Peppers Artichoke " << endl;
	cout << "Zorba 12 23 28 5 Herb_Chicken Feta Artichoke Red_onion Mushroom"<< endl;
	cout << "Meat_Lovers 10 18 25 6 Pepperoni Sausage Smoked_Pork_Belly Mozzarella Parm Marinara"<< endl;
	cout << "Southtown_Blues 9 17 20 7 Pear Apple Bleu_Cheese Mozzarella Toasted_Almonds Sweet_Onion Garlic_Infused_Oil"<< endl;
	cout << "Margherita 9 17 24 5 Tomato Mozzarella_Fresca Basil Marinara Balsamic_Reduction"<< endl; 

}
/******************************************************
** Program: get_hours()
** Author: stickZ
** Date: 04/29/2019
** Description: getter  
** Input: N/A
** Output: N/A
******************************************************/
hour* Restaurant::get_hours() {
	return week;
}
/******************************************************
** Program: 
** Author: Your Name
** Date: 04/16/2019
** Description:  
** Input:
** Output:
******************************************************/
void Restaurant::view_hours() {
	fstream hourID;
	hourID.open("restaurant_info.txt");
	string temp;
	getline(hourID,temp);
	name = temp;
	//cout << name <<  endl;
	getline(hourID,temp);
	phone = temp;
	//cout << phone << endl;
	getline(hourID,temp);
	address = temp;
	//cout << address << temp;
	string lol;
	for(int i =0; i < 7; i++){
		hourID >> week[i].day;
		cout << week[i].day << " ";
		hourID >> week[i].open_hour;
		cout << week[i].open_hour << " ";
		hourID >> week[i].close_hour;
		cout << week[i].close_hour << endl;
	}




}

