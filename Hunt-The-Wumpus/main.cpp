/*****************************************************
** Program: Hunt the Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description:
******************************************************/
#include<iostream>
#include<ctime>
#include<cstring>
#include"game.hpp"
#include<vector>
using namespace std;
int main(int argc, char** argv){
	int size = atoi(argv[1]);
	//char * input = argv[3];
	int result = strcmp(argv[2],"true");
	int result2 = strcmp(argv[2],"false");
	bool lol = false;
	do {
		if(size < 4){
			cout<<"you have to enter a size that is bigger than that (4 or bigger)"<<endl;
			cin>>size;
		}
		else {
			lol = true;
		}
	} while(lol == false);
	Game x(size);
	x.randGen();
	if(result == 0) {
		cout << "------------------------------------" << endl;
		cout << "W is for Wumpus" << endl;
		cout << "B is for super bat" << endl;
		cout << "G is for gold" << endl;
		cout << "P is for pit" << endl;
		cout << "0 is the player" << endl;
		cout << "------------------------------------" << endl;
		cout << endl;
		cout << "the map: " << endl;
		x.print_map();
		exit(0);	
	} else if (result2 == 0) {}
	else {
		cout << "invalid cmd args. " << endl;
		exit(0);
	}
	bool over = false;
	string option; 
	bool check=false; 
	x.start_game();
	x.print_map();
	x.event_check();
	do{
		while(!over){
			cout<<"What to do in this cave?: "<<endl;
			cout << "1. Move around " << endl;
			cout << "2. Shoot an arrow " << endl;
			cout << "anything to quit game" << endl;
			cin >>option;

			if(option == "1"){
				if(x.choose_direction() == 1){			
					break;
				}
			}
			else if(option == "2"){
				if(x.shootingArrow() == 1){
					break;
				}	
			}
			else {
				cout << "Bye Bye" << endl;
				//check = true;
				exit(0);
			}
				//x.print_map();
			}
		if(option == "0"){
			check = true;
		}	
		else{	
			string Y;
			cout << "Do You Want To x Again? yes (1) | no (2): ";
			cin >> Y;
			if (Y == "1") {
				cout << "------------------------------" << endl;
				cout << "....making a new random map..." << endl;
				cout << "------------------------------" << endl;
				x.randGen();
				x.start_game();
				x.print_map();
				x.event_check();
			}
			else if(Y == "0") {
				check = true;
			}	
			else { 
				cout << "that was an invalid input, so bye" << endl;
				check = true;
			}
		}
	
	} while (check == false);
	return 0;
}

       



