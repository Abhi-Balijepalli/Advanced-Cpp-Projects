/* Program: Zoo_Tycoon.cpp
 * Author: StickZ
 * Date: 05.12.2019
 * Description: fun zoo tycoon game, where players play till they loose all thier money
 * Input: options to choose animal, and if you want to buy
 * Ouput: money, profit, bonuses, etc...
 */
#include <iostream>
#include "./zoo.h"
#include <string>
#include <cstdlib>
using namespace std;
/*********************************
 * Name: Zoo()
 * Description: Constructor
 ********************************/
Zoo::Zoo() {
	monkeys = new Animal *[25];
	meerkats = new Animal *[25];
	seaotters = new Animal *[25];
	monkeySize = 25;
	meerkatSize = 25;
	seaotterSize = 25;
	bank = 100000;
	attenBoom = 0;
	for (int i = 0; i < 25; i++) {
		monkeys[i] = NULL;
		meerkats[i] = NULL;
		seaotters[i] =  NULL;
	}
}
/*********************************
 * Name: Zoo()
 * Description: copy - Constructor
 ********************************/
Zoo::Zoo(const Zoo &copy) {
	monkeySize = copy.monkeySize;
	meerkatSize = copy.meerkatSize;
	seaotterSize = copy.seaotterSize;
	bank = copy.bank;
	attenBoom = copy.attenBoom;
	monkeys = new Animal*[monkeySize];
	meerkats = new Animal*[meerkatSize];
	seaotters = new Animal*[seaotterSize];
}
/*********************************
 * Name: Zoo()
 * Description: assignment operator
 ********************************/
const Zoo &Zoo::operator = (const Zoo &copy) {
	delete [] monkeys;
	delete [] meerkats;
	delete [] seaotters;
	monkeySize = copy.monkeySize;
	meerkatSize = copy.meerkatSize;
	seaotterSize = copy.seaotterSize;
	bank = copy.bank;
	attenBoom = copy.attenBoom;
	monkeys = new Animal*[monkeySize];
	meerkats = new Animal*[meerkatSize];
	seaotters = new Animal*[seaotterSize];
}

/*********************************
 * Name: Destructor
 * Description: Deletes dynamic memory
 ********************************/
Zoo::~Zoo() {
	int i = 0;
	while(monkeys[i] != NULL) {
		delete [] monkeys[i];
		i++;
	}
	i = 0;
	while(meerkats[i] != NULL) {
		delete [] meerkats;
		i++;
	}
	i = 0;
	while(seaotters[i] != NULL) {
		delete [] seaotters;
		i++;
	}
}
/*********************************
 * Name: get_bank_money()
 * Description: returns the amount of money you have in bank
 ********************************/
float Zoo::get_bank_money() {
	return bank;
}
/*********************************
 * Name: make_revenue(int )
 * Description: adds revenue to the bank
 ********************************/
void Zoo::make_revenue(int foo) {
	bank += foo;
}
/*********************************
 * Name: take_revenue(int )
 * Description: takes money away from the bank
 ********************************/
void Zoo::take_revenue(int fi) {
	bank -= fi;
}
/*********************************
 * Name: animal_list(animal *)
 * Description: this will check if the type of the animal matches and then goes to the array so there are no segfaults
 ********************************/
void Zoo::animal_list(Animal *yeet) {
	if(yeet->getAnimalType() == "Monkey") {
		add_monkey(yeet);
	}
	else if (yeet->getAnimalType() == "Sea otter") {
		add_seaotter(yeet);
	} else if (yeet->getAnimalType() == "meerkat") {
		add_meerkat(yeet);
	} 
}
/*********************************
 * Name: chooseAnimal()
 * Description: this is the starting where the person has to choose the correct animal
 ********************************/
void Zoo::ChooseAnimal() {
	string i;
	cout << "what animal would you like to buy: " << endl;
	cout << "1. Meerkat      2. SeaOtter    3.Monkey" << endl;
	getline(cin,i);
	if(i == "Monkey" || i == "3") {
		monkeyPurchase();
	} else if (i == "Meerkat" || i == "1") {
		meerkatPurchase();
	} else if (i == "SeaOtter" || i == "2") {
		seaotterPurchase();
	} else {
		cout << "invalid input, ending program...."<< endl;
		exit(0);
	}
}
/*********************************
 * Name: monkeyPurchase()
 * Description: amount of monkeys you want to buy
 ********************************/
void Zoo::monkeyPurchase() {
	string pick;
	cout << "Cool! Monkeys are $15,000. It looks like you have $" << get_bank_money() << " in you account" << endl;
	cout << "you can buy up to 2 monkeys (choose one option): " << endl;
	cout << "1) 1 monkey" << endl;
	cout << "2) 2 monkeys" << endl;
	getline(cin,pick);
	if (pick == "1") {
		take_revenue(15000);
		cout << "you bought 1 monkey so thats -$15,000 from you bank account. Now you have: $" << get_bank_money() << endl;
		animal_list(new Monkeys());
		//add_monkey(new Monkeys());
	} else if (pick == "2") {
		int math = 15000*2;
		take_revenue(math);
		cout << "you bought 2 monkeys so thats -$30,000 from your bank account. Now you have: $" << get_bank_money() << endl;
		animal_list(new Monkeys());
		animal_list(new Monkeys());
		//add_monkey(new Monkeys());
		//add_monkey(new Monkeys());
	}
}
/*********************************
 * Name: meerkatPurchase()
 * Description: you can buy up to 2 meerkats
 ********************************/
void Zoo::meerkatPurchase() {
	string pick;
	cout << "Cool! Meerkats are $500. It looks like you have $" << get_bank_money() << " in you account" << endl;
	cout << "you can buy up to 2 meerkats (choose one option): " << endl;
	cout << "1) 1 meerkat" << endl;
	cout << "2) 2 meerkat" << endl;
	getline(cin,pick);
	if (pick == "1") {
		take_revenue(500);
		cout << "you bought 1 meerkat so thats -$500 from you bank account. Now you have: $" << get_bank_money() << endl;
		//add_meerkat(new Meerkat());
		animal_list(new Meerkat());
	} else if (pick == "2") {
		//int math = 15000*2;
		take_revenue(1000);
		cout << "you bought 2 meerkats so thats -$1000 from your bank account. Now you have: $" << get_bank_money() << endl;
		//add_meerkat(new Meerkat());
		//add_meerkat(new Meerkat());
		animal_list(new Meerkat());
		animal_list(new Meerkat());
	}
}
/*********************************
 * Name: seaotterPurchase()
 * Description: you can buy upto 2 seaotters
 ********************************/
void Zoo::seaotterPurchase() {
	string pick;
	cout << "Cool! Sea-Otters are $5,000. It looks like you have $" << get_bank_money() << " in you account" << endl;
	cout << "you can buy up to 2 Sea-Otters (choose one option): " << endl;
	cout << "1) 1 Sea_Otters" << endl;
	cout << "2) 2 Sea-Otters" << endl;
	getline(cin,pick);
	if (pick == "1") {
		take_revenue(5000);
		cout << "you bought 1 Sea-Otter so thats -$5,000 from you bank account. Now you have: $" << get_bank_money() << endl;
		animal_list(new Meerkat());
	} else if (pick == "2") {
		int math = 5000*2;
		take_revenue(math);
		cout << "you bought 2 Sea-Otters so thats -$10,000 from your bank account. Now you have: $" << get_bank_money() << endl;
		animal_list(new Meerkat());
		animal_list(new Meerkat());
	}
}
/*********************************
 * Name: add_monkey(Animal* )
 * Description: this will add monkeys to the zoo
 ********************************/
void Zoo::add_monkey(Animal *item) {
	if (arraychecker(monkeys,monkeySize)) {
		restructureArray(monkeys,monkeySize);
	}
	for (int i =0; i < monkeySize; i++) {
		if(monkeys[i] == NULL) {
			monkeys[i] = item;
			//cout << "amt monkeys: " << monkeys[i] << endl;
		}
		break;
	}
}
/*********************************
 * Name: add_meerkat(Animal *)
 * Description: this will add meerkats to the zoo and check if the array needs to be resized
 ********************************/
void Zoo::add_meerkat(Animal *item) {
	if (arraychecker(meerkats,meerkatSize)) {
		restructureArray(meerkats,meerkatSize);
	}
	for (int i =0; i < meerkatSize; i++) {
		if(meerkats[i] == NULL) {
			meerkats[i] = item;
			//cout << "amt meerkats: " << meerkats[i] << endl;
		}
		break;
	}
}
/*********************************
 * Name: add_seaotter(Animal *)
 * Description: this will add seaotters to the zoo and check if the array needs to be resized
 ********************************/
void Zoo::add_seaotter(Animal *item) {
	if (arraychecker(seaotters,seaotterSize)) {
		restructureArray(seaotters,seaotterSize);
	}
	for (int i =0; i < seaotterSize; i++) {
		if(seaotters[i] == NULL) {
			seaotters[i] = item;
			//cout << "amt seaotters: " << seaotters[i] << endl;
		}
		break;
	}
}
/*********************************
 * Name: arraychecker(Animal **, int )
 * Description: this will be used in the add_(animal) function
 ********************************/
bool Zoo::arraychecker(Animal **test, int x) {
	for(int i = 0; i < x; i++) {
		if(!test[i]) {
			return false;
			break;
		}
	}
	return true;
}
/*********************************
 * Name: restructureArray(Animal **&, int &)
 * Description: this will be increase the size of array if needed
 ********************************/
void Zoo::restructureArray(Animal **&test, int &x) {
	Animal **arr = new Animal *[x*2];

	for(int i = 0; i < (x*2); i++) {
		arr[i] = NULL;
	}
	for(int i = 0; i < x; i++) {
		arr[i] = test[i];
	}
	delete [] test;
	test = arr;
	x = x*2; 

}
/*********************************
 * Name: runGame()
 * Description: lol, it runs the game - it uses elements that are from the animal.h
 ********************************/
void Zoo::runGame() {
	cout << "....starting Zoo tycoon...." << endl;
	//cout << "this is week 0, so you have to buy an animal. " << endl;
	ChooseAnimal();
		int week = 0;
		int cost_of_food = 0;
		int netGain;
	while(true) {
		attenBoom = 0;
		netGain = 0;
		cout << "week: " << week << endl;
		//display();
		animalGrowth();
		cost_of_food = foodCosts();
		take_revenue(cost_of_food);
		cout << "$"<<foodCosts()<< " were taken out of your bank for food costs for the animals. " << endl;
		cout << "you have $" << get_bank_money() << " in your bank" << endl;
		cout << "------------------------------------" << endl;
		cout << "Now it is time for the random event: " << endl;
		randomEvent();
		cout << "week summary: " << endl;
		//take_revenue(cost_of_food);
		cout << "profit from animals: " << calcPay() << endl;
		cout << "cost for food: " << foodCosts() << endl;
		if(attenBoom != 0) {
			netGain = ((calcPay() - foodCosts()) + attenBoom);
			//cout << "bonus money generated are: " << attenBoom << endl;
			cout << "this week's net gain: $" << netGain << endl;
		} else {
			netGain = (calcPay() - foodCosts());
			cout << "this week's net gain: $"<< netGain << endl;	
			if (get_bank_money() <= 0) {
				cout << "you finished all your money. so its gameover! " << endl;
				exit(0);
			}
		}
		make_revenue(netGain);
		cout << "Money in Bank now: $" <<get_bank_money() << endl;
		//display();
		laterPurchases();
		week++;
		string x;
		cout << "do you want to quit (1) yes, (2) no : " << endl;
		cin >> x;
		if (x == "1") {
			cout << "bye bye, you had $" << get_bank_money() << " in your bank" << endl;
			break;
			//exit(1);
		}

	deleteArrays();
	}
	
	//deleteArrays();
}
/*********************************
 * Name:randomEvent()
 * Description: this will call a random event and go to a randomevent used the rand() function
 ********************************/
void Zoo::randomEvent() {
	int choice = (rand()%4 + 1);
	if(choice == 1) {
		cout << "An animal in your Zoo has gotten sick" << endl;
		sickAnimal();
	} else if( choice == 2) {
		cout << "An adult animal has given birth to (a) babies/baby " << endl;
		babyBorn();
	} else if(choice == 3) {
		cout << "There is a boom in attendence " << endl;
		attendenceBoom();
		//break;
	} else if(choice == 4) {
		cout << "nothing happend today" << endl;
	} else {
		//return randomEvent();
	}
	//choice = 0;
}
/*********************************
 * Name: sickAnimal()
 * Description: checks which animal should be sick and calls it
 ********************************/
void Zoo::sickAnimal() {
	int random = (rand()%3 + 1);
	if(random == 1) {
		sickMonkey();
	} else if(random == 2) {
		sickMeerkat();
	} else if (random == 3) {
		sickSeaotter();
	} else {}
}
/*********************************
 * Name: sickMonkey()
 * Description: self explanatory
 ********************************/
void Zoo::sickMonkey() {
	if(monkeys[0] != NULL) {
		if(get_bank_money() >= 7500) {
			cout << "you have to pay $7500 to treat your monkey: " << endl;
			take_revenue(7500);
			cout << "nice, you helped your animal out. Now you have $" << get_bank_money() << " in your bank" << endl;
		} else {
			cout << "you don't have enough money, so the monkey has died" << endl;
			deadMonkey();
		}
	} else {
		deadMonkey();
	}
}
/*********************************
 * Name: deadMonkey()
 * Description: monkey dies
 ********************************/
void Zoo::deadMonkey() {
	cout << "i'm sorry, you have $" << get_bank_money() << " in your bank" << endl;
	//int last;
	int i = 0;
	while (monkeys[i] != NULL) {
		//int last = i;
		i++;
	}
	delete monkeys[i-1];
	monkeys[i-1] = NULL;	
}
/*********************************
 * Name: sickMeerkat()
 * Description: self explanatory - gets called from the sickAnimal()
 ********************************/
void Zoo::sickMeerkat() {
	if(meerkats[0] != NULL) {
		if(get_bank_money() >= 250) {
			cout << "you have to pay $250 to treat your Meerkat: " << endl;
			take_revenue(250);
			cout << "nice, you helped your animal out. Now you have $" << get_bank_money() << " in your bank" << endl;
		} else {
			cout << "you don't enough money, so the meerkat has died" << endl;
			deadMeerkat();	
		}
	} else {
		sickSeaotter();
	}
}
/*********************************
 * Name: deadMeerkat()
 * Description: meerkat dies
 ********************************/
void Zoo::deadMeerkat() {
	cout << "i'm sorry, you have $" << get_bank_money() << " in your bank" << endl;
	//int last;
	int i = 0;
	while (meerkats[i] != NULL) {
		//int last = i;
		i++;
	}
	delete meerkats[i-1];
	meerkats[i-1] = NULL;	
}
/*********************************
 * Name: sickSeaotter()
 * Description: seaotter falls sick
 ********************************/
void Zoo::sickSeaotter() {
	if(meerkats[0] != NULL) {
		if(get_bank_money() >= 2500) {
			cout << "you have to pay $2500 to treat your Seaotter "<< endl;
			take_revenue(2500);
			cout << "nice, you helped your animal out. Now you have $" << get_bank_money() << " in your bank" << endl;
		} else {
			cout << "you don't have enough money, so the sea otter has died" << endl;
			deadSeaotter();
		}
	} else {
		sickMonkey();
	}
}
/*********************************
 * Name: deadSeaotter()
 * Description: the seaotter dies
 ********************************/
void Zoo::deadSeaotter() {
	cout << "i'm sorry, you have $" << get_bank_money() << " in your bank" << endl;
	//int last;
	int i = 0;
	while (seaotters[i] != NULL) {
		//int last = i;
		i++;
	}
	delete seaotters[i-1];
	seaotters[i-1] = NULL;	
}
/*********************************
 * Name: attendenceBoom()
 * Description: called from the randomEvent(), this will give you revenue and some animals give more
 ********************************/
void Zoo::attendenceBoom() {
	int totalMonkeys = 0;
	int dinero;
	int i = 0;
	while(monkeys[i] != NULL) {
		i++;
		totalMonkeys = i;
	}	
	if (totalMonkeys != 0) {
		int money  = (rand() % 300 + 1) + 400;
		dinero = (totalMonkeys)* money;
		//attenBoom = dinero;
		cout << "because of the attendence boom, your monkey(s) got you $" << dinero << " added to your bank" << endl;
		//int m = (int)dinero;
		make_revenue(dinero);
		attenBoom = dinero;
		cout << "amount of money in bank now: " << get_bank_money() << endl;	
		money = 0;
	}
	else {
		cout << "well you don't have any monkeys so you didn't make any money" << endl;
	}
}
/*********************************
 * Name: babyBorn()
 * Description: a new baby (1,2,5) gets born and will be added to the Zoo with an age of 0.
 ********************************/
void Zoo::babyBorn() {
	int choice = (rand()%3 +1);
	//int i = 0;
	bool Mocheck = false;
	bool Mecheck = false;
	bool Scheck = false;
	if(choice == 1) {
		int i = 0;
		while(monkeys[i] != NULL) {
			if(monkeys[i]->get_Age() >= 49) {
				cout << "there is a new addition to the monkey family; a baby. " << endl;
				//add_monkey(new Monkeys(0));
				animal_list(new Monkeys(0));
				Mocheck = true;
				break;
			}
			i++;
		}
	}if (choice == 2) {
		int i = 0;
		while(meerkats[i] != NULL) {
			if(meerkats[i]->get_Age() >= 49) {
				cout << "there are 2  new addition to the meerkat family; 2 babies. " << endl;
				//add_meerkat(new Meerkat(0));
				//add_meerkat(new Meerkat(0));
				animal_list(new Meerkat(0));
				animal_list(new Meerkat(0));
				Mecheck = true;
				break;
			}
		}
		i++;
	} if (choice == 3) {
		int i = 0;
		while(seaotters[i] != NULL) {
			if(seaotters[i]->get_Age() >= 49) {
				cout << "there are 5 new addition to the seaotter family; 5 babies. " << endl;
				animal_list(new Seaotter(0));
				animal_list(new Seaotter(0));
				animal_list(new Seaotter(0));
				animal_list(new Seaotter(0));
				animal_list(new Seaotter(0));
				Scheck = true;
				break;
			}
		}
		i++;
	}
	if (Mocheck == false) {
		cout << "there are no monkeys that can give birth" << endl;
	} else if (Mecheck == false) {
		cout << "there are no meerkats that can give birth" << endl;
	} else if (Scheck == false) {
		cout << "there are no seaotters that can give birth" << endl;
	}
}
/*********************************
 * Name: laterPurchases()
 * Description: this will be called later if the player wants to by adult animals of 3 different types
 ********************************/
void Zoo::laterPurchases() {
	string choice;
	cout << "would you like to buy an Animal (adult): " << endl;
	cout << " Y / N " << endl;
	cin >> choice;
	if (choice == "Y"){
		string x;
		cout << "what would you like:  1) monkey  |   2) meerkat  |  3) seaotter" << endl;
		cout << "                        ($15000) |      ($500)   |     ($5000) " << endl;
		cin >> x;
		if (x == "1" || x == "monkey") {
			if(get_bank_money() < 15000) {
				cout << "you don't have enough money to buy the monkey becuase you have $" << get_bank_money() << " in your bank" << endl;
			}
			else {
				cout << "nice, you just purchased a monkey ($15000). Now you have $" << get_bank_money() << " in your bank" << endl;	
				//add_monkey(new Monkeys(50));
				animal_list(new Monkeys(50));
				take_revenue(15000);
			}
		}
		if (x == "2" || x == "meerkat") {
			if(get_bank_money() < 500) {
				cout << "you don't have enough money to buy the meerkat becuase you have $" << get_bank_money() << " in your bank" << endl;
			}
			else {
				cout << "nice, you just purchased a meerkat ($500). Now you have $" << get_bank_money() << " in your bank" << endl;	
				//add_meerkat(new Meerkat(50));
				animal_list(new Meerkat(50));
				take_revenue(500);
			}
		}
		if (x == "3" || x == "seaotter") {
			if(get_bank_money() < 5000) {
				cout << "you don't have enough money to buy the seaotter becuase you have $" << get_bank_money() << " in your bank" << endl;
			}
			else {
				cout << "nice, you just purchased a seaotter ($5000). Now you have $" << get_bank_money() << " in your bank" << endl;	
				//add_seaotter(new Seaotter(50));
				animal_list(new Seaotter(50));
				take_revenue(5000);
			}
		}
	} else if (choice == "N") {
		cout << "ok you are not buying an animal. " << endl;
	} else {
		cout << "invalid input, crashing program " << endl;
		exit(0);
	}
}
/*********************************
 * Name: foodCosts()
 * Description: this will calculate the cost of food
 ********************************/
int Zoo::foodCosts() {
	int weekCosts = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	while(monkeys[i] != NULL) {
		weekCosts += 4 * monkeys[i]->get_Base_food();
		i++;
	}
	while(meerkats[j] != NULL) {
		weekCosts += meerkats[i]->get_Base_food();
		j++;
	}
	while(seaotters[k] != NULL) {
		weekCosts += seaotters[i]->get_Base_food();
	}
	return weekCosts;
}
/*********************************
 * Name: display()
 * Description: this will display the amount of animals in the Zoo
 ********************************/
void Zoo::display() {
	cout << "the animals in your Zoo: " << endl;
	int monkeyNum = 0;
	int seaotterNum = 0;
	int meerkatNum = 0;
	int i = 0;
	while(monkeys[i] != NULL) {
		i++;
		monkeyNum++;
	}
	i = 0;
	while(seaotters[i] != NULL) {
		i++;
		seaotterNum++;
	}
	i = 0;
	while(meerkats[i] != NULL) {
		i++;
		meerkatNum++;
	}
	cout << "monkeys: " << monkeyNum << endl;
	cout << "seaotters: " << seaotterNum << endl;
	cout << "meerkats: " << meerkatNum << endl;
}
/*********************************
 * Name: animalGrowth()
 * Description: this will measure the age of the animals
 ********************************/
void Zoo::animalGrowth() {
	int i = 0;
	while(monkeys[i] != NULL) {
		monkeys[i] ->age_week();
		i++;
	}
	i = 0;
	while(seaotters[i] != NULL) {
		seaotters[i]-> age_week();
		i+=7;
	}
	i = 0;
	while(meerkats[i] != NULL) {
		meerkats[i] ->age_week();
		i+=7;
	}
}
/*********************************
 * Name: calcPay()
 * Description: this will be used in calculating profit in the runGame() function
 ********************************/
int Zoo::calcPay() {
	int i = 0;
	int totalM = 0;
	while(monkeys[i] != NULL) {
		totalM += monkeys[i] ->get_revenue();
		i++;
	}
	i = 0;
	while(seaotters[i] != NULL) {
		totalM += seaotters[i]-> get_revenue();
		i++;
	}
	i = 0;
	while(meerkats[i] != NULL) {
		totalM += meerkats[i] ->get_revenue();
		i++;
	}
	return totalM;

}
void Zoo::deleteArrays() {
	int i = 0;
	while (monkeys[i] != NULL) {
		delete [] monkeys[i];
		i++;
	}
	i = 0;
	
	while (meerkats[i] != NULL) {
		delete [] meerkats[i];
		i++;
	}
	i = 0;
	while (seaotters[i] != NULL) {
		delete [] seaotters[i];
		i++;
	}
	//i = 0;
	delete [] monkeys;
	delete [] meerkats;
	delete [] seaotters;

}


