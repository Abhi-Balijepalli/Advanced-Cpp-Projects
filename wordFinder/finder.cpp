/* Input: paragraph, words to search, the amount of words you want to search,  
 * Ouput: frequency
 * Description: a simple word searching algorithm that is like using cntrl + F in real life but more complicated. long story short, hardest assignment ever and i am quesitons life decisions.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

//void startingString(char *sentence);             ---> used for debugging
int wordCounter(char* fpara);
void searching (int *y1);
void lowerCase(char *paragraph);
void searchingPart2(char*paragraph, int x, int *y1);

int main() { 
	int y1;
	string fpara;
	char paragraph[2555];
	cout << "enter a paragraph: ";
	cin.getline(paragraph, 2555);        // char array that takes in a parargraph as the user input

	int length = wordCounter(paragraph);

	searching(&y1);
	searchingPart2(paragraph, length, &y1);
	wordCounter(paragraph);
}

// asking the user how many words you are searching
void searching(int *y1) {
	// the amount of words
	cout << "how many words are you searching: ";
	cin >> *y1;
	cin.ignore(1,'\n');                              

}

// this is the core of the assignment, it will do lowercasing, and frequency and take in words as an array
void searchingPart2(char*paragraph, int x, int *y1){
	int y = *y1; //amount of words
	char *finalArray[x];
	char *temp; //just a temperary char *
	char **arr = new char *[y];
	int counter = 0;
	int finalCounter;            

	for(int i = 0; i < y; i++) {
		cout << "enter word ("<<i+1 << ") :";
		arr[i] = new char[2555];
		cin.getline(arr[i],2555);
		lowerCase(arr[i]);
	}
	cout << endl;
	temp = strtok(paragraph, " ");
	for(int i =0; i<x; i++) {
		finalArray[i] = temp;
		temp = strtok(NULL, " ");
		lowerCase(finalArray[i]);
	}
	for(int i =0; i < y; i++) {
		for(int j = 0; j < x;  j++) {
			//cout << "placeholder" << endl;              ---> used for debugging
			if(true){cout << " ";}
			if(strcmp(arr[i],finalArray[j]) == 0) {
			       counter+=1;
			}
		}
		cout << "the word <"<< arr[i] << "> is in the paragraph: " << counter << " times." << endl;
		counter = 0;	
	}
	for (int i =0; i < y; i++) {                                                                      
	 	delete [] arr[i]; 
	}   
	delete arr;        
} 
              
//this will count how many words the user has put into the original string, its just a checker to see if array lengths match up
int wordCounter(char* fpara){
	int num = 0;
        int width = 0;
	if(fpara == NULL) {
        	return 0;
        }                  
	while(*fpara) {
		if (*fpara == ' '){
			width = 0;
		}
		else if(++width == 1) {
		num++;
		}	
		fpara++;
	}
	return num;
}

//simple function to ignore letter casing 
void lowerCase(char *paragraph) {
	for(int i =0; i < paragraph[i]; i++) {
		paragraph[i] = tolower(paragraph[i]);
	}
}






































       
