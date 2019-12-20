// driver file to run all the code
#include "./list.hpp"
#include <string>
#include <cstdlib>
int main() {
	int num;
	char choice;
	bool input = true;
	Linked_List arr;
	while(input == true) {
		cout << "Enter a number: ";
		cin >> num;
		arr.push_back(num);
		cout << "do you want to enter another number(Y/N): ";
		cin >> choice;
		if(choice == 'Y' || choice == 'y') {input = true;}
		else if(choice == 'N' || choice == 'n') {
			input = false;
		} else {
			cout << "you chose a invalid input" << endl;
			exit(0);
		}
	}
	arr.controller();
	//arr.insert(3,0);
	//arr.insert(10,1);
	string x;
	cout << "do you want to go again? (y/n): ";
	cin >> x;
	if(x == "y") {
		return main();
	} else {
		return 0;
	}
}
