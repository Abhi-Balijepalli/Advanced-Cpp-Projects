/* Program: assign1.cpp
 * Author: Mac $ Cheese
 * Date: 4/14/2019
 * Description: pogwards program that will store spells according a wizard, and their status as role in the school. 
 * you will also store different ways to sort the spells.
 * Input: userID,password,sorting type, if you want to redo or not.
 * Output:sorting, display of status in school, and redo the sorting or quit the program.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "./wizard.h"                        
using namespace std;

/***********************************************************************
 *function: wizard* boonk(char* file);
 *description: this is the first function that will take in the command line argument and open that file using ifstream
 *parameters: char *file
 *pre-conditions: it's a CMD line argument
 *post-condition: it will then go to password/ID prompt
 ***********************************************************************/
wizard* boonk(char* file) {
	ifstream fin;
	fin.open(file);
	if (!(fin.is_open())) {
		cout << "error, you can't do that bruhhh" << endl;
		exit(0);
	}
	string temp;
	getline(fin, temp, '\n');
	int startAmt = atoi(temp.c_str());
	wizard *arr = new wizard[startAmt];
	for (int i = 0; i < startAmt; i++) {
		getline(fin,temp,' ');
		arr[i].name= temp;
		getline(fin,temp,' ');
		arr[i].id = atoi(temp.c_str());
		getline(fin,temp,' ');
		arr[i].password = temp;
		getline(fin,temp,' ');
		arr[i].position_title = temp;
		getline(fin,temp);
		arr[i].beard_length = atof(temp.c_str());
	}
	starting_Part(arr,startAmt);
	return arr;

}
/***********************************************************************
 *function: error_handle(string *temp);
 *description: this method will check for error handling
 *parameters: string *temp
 *pre-conditions: takes user input from ID and checks if its correct
 *post-condition: prompts password if it works
 ***********************************************************************/
void error_handle(string *temp) {
	string handleTemp = *temp;
	bool dank = false;
	while(dank == false){
		for(int i =0; i < handleTemp.length(); i++) {
			if(!(handleTemp.at(i) >= '0' && handleTemp.at(i) <= '9')) {
				cout << "invalid username/password so you outta try again: ";
				getline(cin,handleTemp);
				break;
			} else {
				dank = true;
			}
		}
	*temp = handleTemp;
	}
}
/***********************************************************************
 *function: starting_part(wizard *arr, int amt)
 *description: this is the function that will deal will User ID and password
 *parameters: wizard *arr and int amt
 *pre-conditions: takes in the array of the wizard struct and amt is the size
 *post-condition: this will check if you are granted to pass the file to access other things
 ***********************************************************************/
void starting_Part(wizard *arr, int amt){
	string id_num;
	string pass;
	int index_true;
	int attempts = 0;
	bool indentify;
	do {
		cout << "please enter your id: ";
		getline(cin,id_num);
		error_handle(&id_num); //error handler to check
		int id_duplicate = atoi(id_num.c_str()); 
		for(int i =0; i < amt; i++){
			if(arr[i].id == id_duplicate) {
				index_true = i;
				indentify = true;
				password(arr,amt,index_true);
				break;	
			}
			else {
				indentify = false;
			}
		}
		if(indentify == false) {
			attempts++;
			cout << "incorrect user-name " << endl;
			cout << "oof, the amount of failed demos: " << attempts << endl;
		} else if(indentify == true) {
			break;
		}
	} while(attempts < 3);
	if(attempts >= 3) {
		cout << "darn, you used too many login attempts" << endl;
		exit(0);
	}

}
/***********************************************************************
 *function: password(wizard *arr, int amt, int index)
 *description: this will see if the password matches the ID inputted
 *parameters: wizard *arr, int amt, int index
 *pre-conditions: the ID and index has to be correct for the password is grant access
 *post-condition: goes on to display current status of the user
 ***********************************************************************/
void password(wizard *arr,int amt, int index) {
	bool goodToGo = false;
	int attempts = 0;
	string login;
	do {
		cout << "Please enter your password: ";
		getline(cin,login);
		if(arr[index].password == login) {
			cout << ".....logging you in...." << endl;
			goodToGo = true;
			break;
		} else {
			attempts++;
			cout << "incorrect password" << endl;
			if(attempts == 3) {
				cout << "too many password attempts" << endl;
				exit(0);
			}
		}
	}while(true && attempts < 3);
	display_status(arr,index);

}
/***********************************************************************
 *function: display_status(wizard *arr, int index)
 *description: will display user status and other information
 *parameters: wizard *arr, int index
 *pre-conditions: password and username has to work
 *post-condition: displays user, and then moves onto get_spellbook_data
 ***********************************************************************/
void display_status(wizard *arr, int index) {
	cout << endl;
	cout << "Welcome: "<< arr[index].name << endl;
	cout << "ID: " << arr[index].id << endl;
	cout << "status: " << arr[index].position_title << endl;
	cout << "Beard Length: " << arr[index].beard_length << endl;
}
/***********************************************************************
 *function: spellbook *create_spellbook(int amt)
 *description: will create a 1D dynamic array, and return it
 *parameters: int amt
 *pre-conditions: has to have a valid amt
 *post-condition: the array will be used in calculating the spellbook data
 ***********************************************************************/
spellbook *create_spellbooks(int amt){
	spellbook *srr = new spellbook[amt];
	return srr;
}
/***********************************************************************
 *function:  void get_spellbook_data(spellbook *srr, int amt, ifstream &bookFile)
 *description: this will take and search title, author, num_pages, book edition, and edition of the spellbook
 *parameters: spellbook *srr, int amt, ifstream &bookFile
 *pre-conditions: spellbook.txt has to exist, from the cmd line arguments
 *post-condition: this will at the same time create another array in spellbook struct that will store the spells and then call the sorting method
 ***********************************************************************/
void get_spellbook_data(spellbook *srr, int amt, ifstream &bookFile) {
	srr = create_spellbooks(amt);
	spell *spellarr;
	string temp;
	int sAmt;
        float finalTotal = 0;
        for (int i = 0; i < amt; i++) {
		getline(bookFile,temp, ' ');
		srr[i].title = temp;
		getline(bookFile,temp,' ');
		srr[i].author = temp;
		getline(bookFile,temp, ' ');
		srr[i].num_pages = atoi(temp.c_str());
		getline(bookFile,temp,' ');
		srr[i].edition = atoi(temp.c_str());
		getline(bookFile,temp);
		srr[i].num_spells = atoi(temp.c_str());
		srr[i].s = create_spells(srr[i].num_spells);
		get_spell_data(srr[i].s,srr[i].num_spells,bookFile); 
		for(int j = 0; j < srr[i].num_spells;j++) {
			finalTotal += srr[i].s[j].success_rate;
		}
		float successRate = finalTotal / (float)srr[i].num_spells;
		srr[i].avg_success_rate = successRate;
		finalTotal = 0;
	}
	option_sort(srr,amt, spellarr, sAmt);
}
/***********************************************************************
 *function: void get_spell_data(spell *s, int amt, ifstream &bookFile);
 *description: this function will create an array for spells and store the name, success rate, and effect
 *parameters: spell *s, int amt, ifstream &bookFile
 *pre-conditions: it has to be called using the get_spellbook_data and then use that knowledge for sorting
 *post-condition: this function will be used for the fictional sorting function
 ***********************************************************************/
void get_spell_data(spell *s, int amt, ifstream &bookFile) {
	string temp;
	for(int x =0; x < amt; x++) {
		getline(bookFile,temp,' ');
		s[x].name = temp;
		getline(bookFile,temp,' ');
		s[x].success_rate = atof(temp.c_str());
		getline(bookFile,temp);
		s[x].effect = temp;
	}
}  
/***********************************************************************
 *function: spell *create_spells(int amt);
 *description: return a spell array
 *parameters: int amt
 *pre-conditions: the functions above have to call this
 *post-condition: it will be used later on in the getspellbookdata function
 ***********************************************************************/
spell *create_spells(int amt) {
	spell *s = new spell[amt];
	return s;
}
/***********************************************************************
 *function: delete_info(wizard** arr, spellbook** srr, int num);
 *description: deletes the unwanted memory
 *parameters: wizard** arr, spellbook** srr, int num
 *pre-conditions: the array has to be made
 *post-condition: memory will be freed
 ***********************************************************************/
void delete_info(wizard** arr,spellbook** srr,int num){
	delete []* arr;
	for(int i =0; i < num; i++) {
		delete [] (*srr)[i].s;
	}
	delete [] (*srr);
}
/***********************************************************************
 *function: void option_sort(spellbook *srr,int amt, spell *spellarr, int samt)
 *description: option to choose which sort you want to
 *parameters: spellbook *srr, int amt, spell *spellarr, int samt
 *pre-conditions: the get_spellbook_data has to pass
 *post-condition: choose your sort, and repromt
 ***********************************************************************/
void option_sort(spellbook *srr,int amt, spell *spellarr, int samt) {
	int choice;
	do {
		cout << "which option would you like to choose? " << endl;
		cout << "Sort spellbooks by number of pages (Press 1): " << endl;
		cout << "Group spells by their effect (Press 2): " << endl;
		cout << "Sort spellbooks by average success rate (Press 3): " << endl;
		cout << "if you want to quit (press 4): " << endl;
		cin >> choice;
		if(choice == 1) {
			sort_by_pages(srr,amt);	
		} else if(choice == 2) {
			cout << "i dont have that done, sorry" << endl;
			exit(0);
		} else if (choice == 3) {
			sort_avg_succ(srr,amt);
		} else if(choice == 4) {
			cout << "bye bye" << endl;
			exit(0);
		} else {
			cout << "you entered something invalid, so bye!" << endl;
			exit(0);
		}
	}while(choice >= 1 && choice <= 3);
}
/***********************************************************************
 *function: sort_by_pages(spellbook *srr, int amt);
 *description: this will sort by spells pages and its title
 *parameters: spellbook *srr, int amt
 *pre-conditions: has to be passed through the sort_option
 *post-condition: print to file or screen -> function
 ***********************************************************************/
void sort_by_pages(spellbook *srr, int amt) {
	int index;
	//cout << amt;
	int staticA[amt];
	string staticT[amt];

	for(int i =0; i < amt; i++) {
		staticA[i] = srr[i].num_pages;
	}
	for (int i =0; i < amt; i++) {
		staticT[i] = srr[i].title;
	}
	for(int i =0; i < amt-1;i++) {
		for(int x =0; x < amt-i-1; x++) {
			if(staticA[x] > staticA[x+1]) {
				int temp = staticA[x];
				staticA[x] = staticA[x+1];
				index = x;
				staticA[x+1] = temp;
				
				string boonker = staticT[x+1];
				staticT[x+1] = staticT[index];
				staticT[index] = boonker;
			}
		}
	}
	transfer_num_pages(staticT,staticA,amt);
}
/***********************************************************************
 *function: sort_avg_succ(spellbook *srr, int amt);
 *description: this will sort according to average success rates
 *parameters: spellbook *srr, int amt
 *pre-conditions: has to be passed by option_sort
 *post-condition: print to file or screen -> function
 ***********************************************************************/
void sort_avg_succ(spellbook *srr, int amt) {
	int index;
	//cout << amt;
	float staticA[amt];
	string staticT[amt];

	for(int i =0; i < amt; i++) {
		staticA[i] = srr[i].avg_success_rate;
	}
	for (int i =0; i < amt; i++) {
		staticT[i] = srr[i].title;
	}
	for(int i =0; i < amt-1;i++) {
		for(int x =0; x < amt-i-1; x++) {
			if(staticA[x] < staticA[x+1]) {
				int temp = staticA[x];
				staticA[x] = staticA[x+1];
				index = x;
				staticA[x+1] = temp;
				
				string boonker = staticT[x+1];
				staticT[x+1] = staticT[index];
				staticT[index] = boonker;
			}
		}
	}
	transfer_num_succ(staticT,staticA,amt);
}
/***********************************************************************
 *function: void transfer_num_succ(string staticT[], int staticA[],int amt);
 *description: choose to print on screen or file
 *parameters: string staticT[], staticA[], int amt
 *pre-conditions: the option sort has to pass
 *post-condition: this will be the last step
 ***********************************************************************/
void transfer_num_pages(string staticT[], int staticA[],int amt) {
	int choice;
	cout << "do you want to print to a file (press 1): " << endl;
	cout << "do you want to print to the screen (press 2): " << endl;
	cin >> choice;
	if(choice == 1) {
		string filename;
		cout << "Enter File Name (.txt): ";
		cin >> filename;
		ofstream output;
		output.open(filename.c_str(), ios::out | ios::trunc);
		for (int i = 0; i < amt; i++) {
			output << staticT[i] << " " << staticA[i] << endl;
		}
		output.close();

	} else if(choice == 2) {
		for(int i =0; i < amt; i++) {
			cout << staticT[i] <<" " <<staticA[i] << endl;
		}
		cout << endl;
	} else {
		exit(0);
	}
}
/***********************************************************************
 *function: void transfer_num_succ(string staticT[], float staticA[],int amt);
 *description: choose to print on screen or file
 *parameters: string staticT[], staticA[], int amt
 *pre-conditions: the option sort has to pass
 *post-condition: this will be the last step
 ***********************************************************************/
void transfer_num_succ(string staticT[], float staticA[],int amt) {
	int choice;
	cout << "do you want to print to a file (press 1): " << endl;
	cout << "do you want to print to the screen (press 2): " << endl;
	cin >> choice;
	if(choice == 1) {
		string filename;
		cout << "Enter File Name (.txt): ";
		cin >> filename;
		ofstream output;
		output.open(filename.c_str(), ios::out | ios::trunc);
		for (int i = 0; i < amt; i++) {
			output << staticT[i] << " " << staticA[i] << endl;
		}
		output.close();

	} else if(choice == 2) {
		for(int i =0; i < amt; i++) {
			cout << staticT[i] <<" " <<staticA[i] << endl;
		}
		cout << endl;
	} else {
		exit(0);
	}
}
