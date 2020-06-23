#include <iostream>
#include <cstdlib>
using namespace std;

void fractal(int astrks, int spaces);

int main(){
	int astrks; // the asterks are the stars
	int spaces; // the spaces are the indentation of the starting stars 

	do {
		cout << "enter the stars you want: ";
		cin >> astrks;
		if (astrks %2 != 0) {
			cout << "it is not a even number so try again" << endl;
		}
	} while (!(astrks %2 == 0));	

	cout << "enter the amount of spaces you need: "; 
	cin >> spaces;    
	fractal(astrks,spaces);
}

// this will deal with the recursion
void fractal(int astrks, int spaces) {	
	if (astrks < 1) {
		return ;	
	}	
	fractal(astrks/2 , spaces); // this will run the fractal function again, aka recursion
	for (int i =0; i <spaces; i++) { // basically the physical interpretation of int spaces
		cout << " ";
	}
	for (int i = 0; i <astrks; i++) { // physical interpretation of int astrks
		cout << "*";
	}
	cout << endl;
	fractal(astrks/2, spaces + astrks/2); // recursion of the fractal;
}

