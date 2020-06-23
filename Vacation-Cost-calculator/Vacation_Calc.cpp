/*****
 * description: this program is a travel reimbersement program that calculates how much money your company will pay back when you travel and how much you have to spend out of pocket
 * input: taxi/ car cost, gas cost, parking fee, hotel cost, light tickets, arrival and departure times
 * output: total reimbursement cost, total money spent, "background operation: food reimbursement specifications"
 ****/

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

// declaring all the methods so that i can use referencec and pointers
void transportation();
int vacation_days(int *days);
void departure_time(float *departure, float *arrival);
float air_fare_cost(float *aircost);
float seminar_cost(float *semCost);
void car_fare_cost(float *rentCost, float *gasCost, int *choice);
void taxi_cost(float *payTaxi, int *days, float *reimbursedCar, int *daysTaxi);
void SUV(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost);
void Sedan(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost);
void Van(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost);
void convertible(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost);
float parking_fee(int *days, float *parkingTotalcost);
float hotel_cost(int *days, float *nightStayCost, int *nightDays, float *arrival, float *totalHotelCost);
void dining_checkerOne(float *departure, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
void diningFinal(int *days, float *breakfast, float *diningTotalCost, float *lunch, float *dinner);
void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost, int *days);
//void myTotalCost();

int main() {
	float arrival;
	float departure;
	//float carCost;
	//float taxiCost; 
	int daysTaxi;
	float breakfast;
	float lunch;
	float dinner;
	float diningTotalCost;
	int days;
	float parkingTotalcost;
	int nightDays;
	//int choice;
	float aircost;
	float semCost;
	float nightStayCost;
	float totalHotelCost;
	//float rentCost;
	//float gasCost;
	float payTaxi;
	float totalCost;
	float finalCost;
	//float reimbursedCar;
	vacation_days(& days);
	departure_time( &departure, & arrival);
	air_fare_cost(&aircost);
	seminar_cost(&semCost);
	transportation();
	parking_fee(&days, &parkingTotalcost);
	hotel_cost(&days, &nightStayCost, &nightDays, &arrival, &totalHotelCost);
	dining_checkerOne(&departure, &breakfast, &lunch, &dinner, &diningTotalCost);
	diningFinal(&days, &breakfast, &diningTotalCost, &lunch, &dinner);
	dining_checkerTwo(&arrival, &breakfast, &lunch, &dinner, &diningTotalCost, &days);
	//myTotalCost();

	// this will give me final cost
	float finalValue = diningTotalCost + parkingTotalcost + aircost + semCost + totalHotelCost + nightStayCost;
	cout << "total cost is: " << finalValue << endl;

	// this is for reimbursement
	float taxiAllowed = 10 * days;
	float hotelAllowed = 90 * days;
	float parkingAllowed = 6 * days;
	float maxRental = 31.25 * days;
	float gasRental = 10 * 0.35;
	float dinnerF = 16 * nightStayCost;
	float lunchF = 12 * nightStayCost;
	float breakastF = 9 * nightStayCost;

	float reimbursableValue = taxiAllowed + hotelAllowed + parkingAllowed + maxRental + dinnerF + lunchF + breakastF;

	// final value for how much you will be reimbursed
	float finalExitValue = finalValue - reimbursableValue;
	if (finalExitValue <= 0) {
		cout << "you have been reimbursed completely"<<endl;
	}
	else {
		cout << "Your total reimbursement for this trip is : $" << finalExitValue <<endl;
	}




	return 0;
}
//**********************************************************************
// this function will calculate the cost of rental car, and the gas cost 
// ******************************************************************
void car_fare_cost(float *rentCost, float *gasCost, int *choice) {
	cout << "Enter total spent on the rental car in $: ";
	cin >> *rentCost;
	cout << "Enter your total gas fee spent in $: ";
	cin >> *gasCost;
	int days;
	float reimbursedCar;
	float totalCost;
	do {
		cout << "1.Sedan       2.SUV       3.Van       4.Convertible" << endl;
		cout << "enter your rental car type: ";
		cin >> *choice;
		if (*choice == 1) {
			Sedan(rentCost, gasCost, &days, &reimbursedCar, &totalCost);
			break;
		}
		else if (*choice == 2) {
			SUV( rentCost,  gasCost, &days, &reimbursedCar, &totalCost);
			break;
		}
		else if (*choice == 3) {
			 Van(rentCost,  gasCost, &days, &reimbursedCar, &totalCost);
			 break;
		}
		else if (*choice == 4) {
			convertible(rentCost, gasCost,  &days, &reimbursedCar, &totalCost);
			break;
		}
		else {
			cout << "invalid input";
		}
	} while (*choice >= 1 && *choice <= 4);
}
// this function is for calculating the cost of one of the cars (sedan) this is basically the same
// for the next four functions
// sedan
// SUV
// Van
// convertible
void Sedan(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost) {
	double miles;
	*totalCost = (*rentCost + *gasCost);
	do {
		cout << "Enter total miles driven, in miles: ";
		cin >> miles;
		double allowedCost = (double) (*days * 20.0) + (0.2400000 * miles);
		*reimbursedCar = (*totalCost - allowedCost);
		break;
	} while (miles >= 0);
}

void SUV(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost) {
	double miles;
	*totalCost = (*rentCost + *gasCost);
	do {
		cout << "Enter total miles driven, in miles: ";
		cin >> miles;
		double allowedCost = (double)(*days * 20.0) + (0.2400000 * miles);
		*reimbursedCar = (*totalCost - allowedCost);
		break;
	} while (miles >= 0);
}

void Van(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost) {
	double miles;
	*totalCost = (*rentCost + *gasCost);
	do {
		cout << "Enter total miles driven, in miles: ";
		cin >> miles;
		double allowedCost = (double)(*days * 20.0) + (0.2400000 * miles);
		*reimbursedCar = (*totalCost - allowedCost);
		break;
	} while (miles >= 0);
}

void convertible(float *rentCost, float *gasCost, int *days, float *reimbursedCar, float *totalCost) {
	double miles;
	*totalCost = (*rentCost + *gasCost);
	do{
		cout << "Enter total miles driven, in miles: ";
		cin >> miles;
		double allowedCost = (double)(*days * 20.0) + (0.2400000 * miles);
		*reimbursedCar = (*totalCost - allowedCost);
		break;
	} while (miles >= 0);
}

// the cost of the taxi, will be calculated and how much will be reimbursed
void taxi_cost(float *payTaxi, int *days, float *reimbursedCar, int *daysTaxi) {
	cout << "Enter how many days did you use the taxi: ";
	cin >> *daysTaxi;
	if (*daysTaxi <= *days) {
		*payTaxi = float(*daysTaxi * 2.15);
		*reimbursedCar = (*daysTaxi * 10) - (*payTaxi);
		cout << *reimbursedCar;
		return;
	}
}

// the basic days function
int vacation_days(int *days) {
	do {
		cout << "Enter the number of days on your trip: ";
		cin >> *days;
		if (*days >= 1) {
			int air_fare_cost(*days);
			break;
		}
		else if (cin.fail()) {
			cout << "invalid input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
		}
		else {
			break;
		}
			
	} while (true);
	return *days;
}
// takes i input for the cost of the flight
float air_fare_cost(float *aircost) {
	bool x = true;
	bool y = true;
	do {
		cout << "Enter total amount of airfare, in $: ";
		cin >> *aircost;
		if (cin.fail()) {
			cout << "invalid input";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
		}
		else {
			x = false;
			y = false;
		}
	} while (x == true && y == true);
	return *aircost;
}
// seminar costs and take that as the input
float seminar_cost(float *semCost) {
	bool x = true;
	bool y = true;
	do {
		cout << "Enter total conference or seminar registration fees, in $: ";
		cin >> *semCost;
		if (!(*semCost > 0)) {
			cout << "invalid input";
			return air_fare_cost(semCost);
		}
		else {
			x = false;
			y = false;
		}
	} while (x == true && y == true);
	return *semCost;
}
// time function
void departure_time(float *departure, float *arrival) {
	bool x = false;
	bool y = false;
	do {
		cout << "enter your arrival time: ";
		cin >> *departure;
		if (*departure <= 23.59 && *departure >= 0.01) {
			x = true;
		}
		else {
			cout << "invalid input";
		}
		cout << "enter your departure time: ";
		cin >> *arrival;
		if (*arrival <= 23.59 && *arrival >= 0.01) {
			y = true;
		}
		else {
			cout << "invalid input";
		}
	} while (!(x == true && y == true));
}

float parking_fee(int *days, float *parkingTotalcost) {
	float parking;
	for (int i = 1; i <= *days; i++) {
		cout << "enter the parking fee for day " << i << ": ";
		cin >> parking;
		*parkingTotalcost += parking;
	}
	return *parkingTotalcost;
}
// calculates costs of the hotel nights
float hotel_cost(int *days, float *nightStayCost, int *nightDays, float *arrival, float *totalHotelCost ) {
	if (*arrival >= 18)
		*nightDays = (*days - 1);
	else
		*nightDays = *days;
	for (int i = 1; i <= *nightDays; i++) {
		cout << "Enter hotel fee for night " << i << ": ";
		cin >> *nightStayCost;
		*totalHotelCost += *nightStayCost;
	}
	return *totalHotelCost;
}
// checks for 1st day
void dining_checkerOne(float *departure, float *breakfast, float *lunch, float *dinner, float *diningTotalCost) {
	if (*departure >= 18) {
		cout << "Day " << 1 << endl;
		cout << "your breakfast for day 1 is not allowed as an expense" << endl;
	}
	else if (*departure >= 12) {
		cout << "Day " << 1 << endl;
		cout << "your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "your lunch for day 1 is not allowed as an expense" << endl;
	}
	else if (*departure >= 7) {
		cout << "Day " << 1 << endl;
		cout << "your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "your lunch for day 1 is not allowed as an expense" << endl;
		cout << "your dinner for day 1 is not allowed as an expense" << endl;
	}
	if( *departure < 7) {
		cout << "Day 1" << endl;
		cout << "Enter breakfast fee: ";
		cin >> *breakfast;

		if (*breakfast <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *breakfast;
		cout << "enter lunch fee: ";
		cin >> *lunch;
		if (*lunch <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *lunch;

		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
	else if (*departure < 12) {
		cout << "Day 1" << endl;
		cout << "your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "enter lunch fee: ";
		cin >> *lunch;
		if (*lunch <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *lunch;

		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
	else if (*departure < 18) {
		cout << "Day " << 1 << endl;
		cout << "your breakfast for day 1 is not allowed as an expense" << endl;
		cout << "your lunch for day 1 is not allowed as an expense" << endl;
		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
	else {
	}
}
// checks for middle days
void diningFinal(int *days, float *breakfast, float *diningTotalCost, float *lunch, float *dinner) {
	for (int i = 2; i <= *days-1; i++) {
		
		cout << "Day " << i << endl;
		cout << "Enter breakfast fee: ";
		cin >> *breakfast;
		
		if (*breakfast <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *breakfast;
		cout << "enter lunch fee: ";
		cin >> *lunch;
		if(*lunch <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *lunch;

		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
}

// checks for last day
void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost, int *days) {
	if (*arrival <= 19) {
		cout << "Day " << *days << endl;
		cout << "your breakfast for day " << *days << " is not allowed as an expense" << endl;
	}
	else if (*arrival <= 1) {
		cout << "Day " << *days << endl;
		cout << "your breakfast for day " << *days << " is not allowed as an expense" << endl;
		cout << "your lunch for day " << *days << " is not allowed as an expense" << endl;
	}
	else if (*arrival <= 8) {
		cout << "Day " << *days << endl;
		cout << "your breakfast for day " << *days << " is not allowed as an expense" << endl;
		cout << "your lunch for day " << *days << " is not allowed as an expense" << endl;
		cout << "your dinner for day " << *days <<" is not allowed as an expense" << endl;
	}
	else if (*arrival >= 8) {
		cout << "Day "<< *days << endl;
		cout << "Enter breakfast fee: ";
		cin >> *breakfast;

		if (*breakfast <= 0) {
			cout << "invalid input";
			void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *breakfast;
		cout << "enter lunch fee: ";
		cin >> *lunch;
		if (*lunch <= 0) {
			cout << "invalid input";
			void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *lunch;

		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
	else if (*arrival >= 13) {
		cout << "Day " << *days << endl;
		cout << "your breakfast for day " << *days << " is not allowed as an expense" << endl;
		cout << "enter lunch fee: ";
		cin >> *lunch;
		if (*lunch <= 0) {
			cout << "invalid input";
			void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *lunch;

		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void diningPlanCost(int *days, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
	else if (*arrival >= 19) {
		cout << "Day " << *days << endl;
		cout << "your breakfast for day " <<*days<<" is not allowed as an expense" << endl;
		cout << "your lunch for day " <<*days <<" is not allowed as an expense" << endl;
		cout << "enter dinner fee: ";
		cin >> *dinner;
		if (*dinner <= 0) {
			cout << "invalid input";
			void dining_checkerTwo(float *arrival, float *breakfast, float *lunch, float *dinner, float *diningTotalCost);
		}
		*diningTotalCost += *dinner;
	}
}

// this function decides if you rented the car or taxi
void transportation() {
	int input;
	float rentCost;
	float gasCost;
	int choice;
	float payTaxi;
	int days;
	int daysTaxi;
	float reimbursedCar;
	do {
		cout << "Did you 1: rent a car or 2: use taxi for your trip? Enter 1 or 2: ";
		cin >> input;
		if (input == 1) {
			car_fare_cost(&rentCost, &gasCost, &choice);
			break;
		}
		else if (input == 2) {
			taxi_cost(&payTaxi, &days, &reimbursedCar, &daysTaxi);
			break;
		}
		else {
			cout << "invalid input" << endl;
			transportation();
		}
	} while (input == 1 || input == 2);
}



