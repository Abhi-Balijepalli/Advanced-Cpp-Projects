#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "./wizard.h"
using namespace std;

int main (int argc, char **argv) {
	int amt;
	spellbook *srr;
	string temp;
	wizard *arr = boonk(argv[1]);
	delete [] arr;
	ifstream spellbk;
	spellbk.open(argv[2]);
	if (!(spellbk.is_open())) {
		cout << "error, you cannot do that bruhhh" << endl;
		exit(0);
	}
	getline(spellbk,temp,'\n');
	amt = atoi(temp.c_str());
	cout << "amt: " << amt << endl;
	get_spellbook_data(srr,amt,spellbk);
	

	//sort_by_pages(srr,amt);	
	//option_sort(srr,amt);
	//delete_info(&arr,&srr,amt);


}
