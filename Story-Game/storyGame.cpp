/**************************************************************************************************************************************************************************
 *Program: assingment2.cpp 
 *Author: Abhi
 *Date: 1/20/2019
 *Description: this program is a simple story mode program where players can play a person entering rooms with only two types of input (1 or 2)
 *Input: enter int 1 or 2
 *output: position - entering different rooms or encountering an interaction of some sort in the story
 ***************************************************************************************************************************************************************************/

#include <iostream> 
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;
int choice;
// this game is about finding your way to save your friend from gettin killed by the bandits who have taken him hostage inside a castle

int main() {
	cout << "welcome player, you have to find your way all the way up to the top of the castle, you have one bullet and the chance to fire it at the guard. enter either 1 or 2 to make your moves: " << endl;
	cin >> choice;
	while (choice == 1 || 2 ) {
	// if statements for different rooms, first choice rooms
		cout << "welcome player, you have to fine your way all the way to the castle, you have one bullet and the chance to fire it at the guard. enter either 1 or 2 to make your moves: " << endl;	
		if (choice == 1) { 
			cout << "you have taken the front entrance!, you can either take the (1) elevator to the top or (2) take the stairs: " << endl;
			cin >> choice;
			if(choice == 1||2) {
				cout << "ok you made it to the top without being caught, you see two doors in front of you! you can either shoot one of the doors at random by chance (1) or shoot through the 2nd door (2) , just saying there is not guarantee the guard is in door 2: " << endl;
				cin >> choice;
				if (choice == 1) {
					int random = (rand()% 10)+1;
						if (random >= 4) {
							cout << "congrats you have killed the guard and saved your friend" << endl;
							cout << "game will restart if you press 1 or 2. if you want to exit type clear" << endl;
						}					
						else {
							cout << "i am sorry, you shot into an empty room " << endl;
							cout << "game will restart if you press 1 or 2. if you want to exit type clear" << endl;
						}
					}
				else if (choice == 2 ) {
					cout << " you accidentally shot your friend and did the guard a favor, sorry :( " << endl;
					cout << "game will restart if you press 1 or 2. if you want to exit type clear" << endl;				
					}						
				}
				else {
					cout << "invalid input" << endl;
				}
			}
	// second way of entering the building
		else if (choice == 2) {
			cout << " wow, you walked through the back entrance of the castle. now you can either jump up through the (1) trampolines and go all the up or go up the ladder that goes up to the top roof" <<  endl;
			cin >> choice;
			if (choice == 1) {
				cout << "ok spiderman, you made it to the top and now you can either (1) secretly sneak pass through the trip mines and then shoot the guard or (2) you can go back and try taking the ladder: " << endl;
				cin >> choice;
				if (choice == 1 ) {
					cout << " you just died buddy, you shouldn't have done that. big oof " << endl;
					cout << "game will retart if you press 1 or 2. if you want to exit type clear" << endl;
				} 
				else {
					cout << " congrats you made it to the roof of the castle, you can either (1) enter in through the window and shoot the guard or take (2)  a chance and depend on supernatural forces: " << endl;
					cin >> choice;
					if( choice == 1) {
						cout << " awesome job you won the game! " << endl;
						cout << "game will restart if you press 1 or 2. if you want to exit type clear." << endl;
					} 
					else {
						int superNat = (rand() % 10 ) + 1; // this function is the chance function, if will pick the rooms for you. 
						if (superNat >= 6) {
							cout << "oof, you got played, you lost." << endl;
							cout << "game will restart if you press 1 or 2. if you want to exit type clear." << endl;
						}
						else {
							cout << " wow, you got lucky " << endl;
							cout << "game will restart if you press 1 or 2. if your want to exit type clear." << endl;
						}
					}
				}	
			}
		 	else if( choice == 2 ) {
				cout << " congrats now you have taken the ladder to the roof of the castle, you can (1) either summon your inner demon and blow the top ofor (2) you can jump through the window and take down the guard using your bullet: " << endl;
				if (choice == 1 ) {
					cout << "that option doesn't exist, you are not in some fantasy" << endl;
					cout << "game will restart if you press 1 or 2. if you want to exit type clear " << endl;
				} 
				else if (choice == 2 ) {
					cout << "congrats you won the game" << endl;
					cout << "game will restart if you press 1 or 2. if you want to exit type clear " << endl;
				} 
			}
		}
		else {
			break;
		}
	}
	cout << "you have to choose between 1 or 2, or you will get destroyed " << endl;
}				


