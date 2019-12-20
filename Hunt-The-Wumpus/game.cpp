/*****************************************************
** Program: Hunt_the_Wumpus
** Author: Abhi
** Date: 05/28/2019
** Description: 
******************************************************/
#include"gold.hpp"
#include"game.hpp"
#include <iostream>
using namespace std;
/*****************************************************
** Function: Game()
** Author: Abhi
** Date: 05/28/2019
** Description: constructs the variables
******************************************************/
Game::Game(){
	xPlane = 0;
	yPlane = 0;
	arrow = 2;
	wumpusStatus = false;
	goldMake = 0;
}
/*****************************************************
** Function: Game(int )
** Author: Abhi
** Date: 05/28/2019
** Description: non-default constructor with a argv values that come in from the cmd line
******************************************************/
Game::Game(int size){

	sizeMap = size;
	for(int r =0; r<size; r++){
		vector<Room*> row;
		for(int c = 0; c< size; c++){
			row.push_back(new Room);
		}
		map.push_back(row);
	}
	xPlane = 0;
	yPlane = 0;
	arrow = 2;
	wumpusStatus = 0;
	goldMake = 0;

}
/*****************************************************
** Function: ~Game()
** Author: Abhi
** Date: 05/28/2019
** Description: frees all the dynamic memory
******************************************************/
Game::~Game(){
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j < sizeMap; j++){
			delete map[i][j];
		}
	}


}
/*****************************************************
** Function: choose_direction()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if your direction is valid
******************************************************/
int Game::choose_direction(){
	string place;
	cout<<"chose your direction: "<<endl;
	cout<<"W. up"<<endl;
	cout<<"S. down"<<endl;
	cout<<"A. left"<<endl;
	cout<<"D. right"<<endl;
	cin >> place;
	if(place == "W"){
		if(area_of_cave(xPlane-1, yPlane)){
			xPlane--;
		}
		else{
			cout<<"out of bounds"<<endl;
		}
	}
	else if(place == "S"){
		if(area_of_cave(xPlane+1, yPlane)){
			xPlane++;
		}
		else{
			cout<<"out of bounds"<<endl;
		}
	}
	else if(place == "A"){
		if(area_of_cave(xPlane, yPlane-1)){
			yPlane--;
		}
		else{
			cout<<"out of bounds"<<endl;
		}
	}
	else if(place == "D"){
		if(area_of_cave(xPlane, yPlane+1)){
			yPlane++;
		}
		else{
			cout<<"out of bounds"<<endl;
		}
	}
	int check = 1;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j < sizeMap; j++){
			if(i == xPlane && j == yPlane){
				identifier = check;
			}
			check++;
		}
	}
	cout << "--------------" << endl;
	cout<<	"Location: "<< identifier <<endl;
	cout << "--------------" << endl;
	if(event_check() == 0){
		return 1;
	}
	area_check();

	if(win() == 1){
		cout<<"congrats you have finally won :)"<<endl;
		return 1;
	}
	return 0;
}				
/*****************************************************
** Function:shootingArrow()
** Author: Abhi
** Date: 05/28/2019
** Description: shoots the arrow
******************************************************/
int Game::shootingArrow(){
	int spot;
	int checker = 1;
	string shootDirect;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j < sizeMap; j++){
			if(i == xPlane && j == yPlane){
				spot = checker;
			}
			checker++;
		}
	}
	cout<<"where do you want to shoot?: "<<endl;
	cout<<"W. up"<<endl;
	cout<<"S. down"<<endl;
	cout<<"A. left"<<endl;
	cout<<"D. right"<<endl;
	cin>>shootDirect;
	if(shootDirect == "W"){
		arrow--;
		for(int i = 1; i<=3; i++){
			if(area_of_cave(xPlane-i, yPlane)){
				cout<< spot - (sizeMap*i)<<endl;
				if(wumpusStatus == false){
					break;
				}

				if(spot - (sizeMap) == wumpusUno){
					cout<<"You killed the wumpus!!"<<endl;
					wumpusStatus = true;
					return 0;
				}
			}
		}
		if(arrow > 0 && wumpusStatus == false)
			return 0;
	}
	else if (arrow <=0 && wumpusStatus == false){
		cout<< "Arrows:0 Wumpus:dead. Now get out!"<<endl;
	}  
	else if(shootDirect == "S"){
		arrow--;
		for(int i = 1; i<=3; i++){
			if(area_of_cave(xPlane+i, yPlane)){
				cout<< spot + (sizeMap*i)<<endl;
				if (wumpusStatus ==false){
					break;
				}			
				if(spot + (sizeMap*i) == wumpusUno){
					cout<<"You killed the wumpus!!"<<endl;
					wumpusStatus = false;
					return 0;
				}
			}
		}
		if(arrow > 0 && wumpusStatus == false){
			return 0;
		}
		else if (arrow <=0 && wumpusStatus == false){
			cout<< "Arrows:0 Wumpus:dead. Now get out!"<<endl;
		}
	}
	else if(shootDirect == "A"){
		arrow--;
		for(int i = 1; i<=3; i++){
			if(area_of_cave(xPlane, yPlane-i)){
				cout<< spot -i <<endl;
				if(wumpusStatus == 1){
					break;
				}
				if(spot - i  == wumpusUno){
					cout<<"You killed the wumpus!!"<<endl;
					wumpusStatus = false;
					return 0;
				}
			}
		}
		if(arrow > 0 && wumpusStatus == false){
			return 0;
		}
		else if (arrow <=0 && wumpusStatus == false){
			cout<< "Arrows:0 Wumpus:dead. Now get out!"<<endl;
		}



	} else if(shootDirect == "D"){
		arrow--;
		for(int i = 1; i<=3; i++){
			if(area_of_cave(xPlane, yPlane+i)){
				cout<< spot + i<<endl;
				if(wumpusStatus == 1){
					break;
				}

				if(spot + i == wumpusUno){
					cout<<"You killed the wumpus!!"<<endl;
					wumpusStatus = false;
					return 0;
				}
			}
		}

		if(arrow > 0 && wumpusStatus == false){
			return 0;
		} else if (arrow <=0 && wumpusStatus == 1){
			cout<< "arrows:0, Wumpus: Dead. Now get out of here!"<<endl;
		}	
	}
	if(wumpusStatus==true){
	}
	else if(wumpusStatus==false){
		return 0;
	}
	if(arrow <= 0 && wumpusStatus == true){
		cout<< "Ran out of arrows so you lost the game"<<endl;
		arrow=2;
		return 1;
	}

	else{

		return 0;
	}

}
/*****************************************************
** Function: wumpus_move()
** Author: Abhi
** Date: 05/28/2019
** Description: when the wumpus moves you will know
******************************************************/
void Game::wumpus_move(){
	int random = rand() % 4; //moves the wumpus in 4 different directions
	if(random == 3){
		cout<<"You shot an arrow and nothing happened"<<endl;
	}
	else{ 
		cout<<"You hear \"it\" move "<<endl;
		int n_event = 1;
		int if_sim = 0;
		int t;
		while(n_event < 7){
			t = rand() % (sizeMap*sizeMap) + 1;
			for(int i = 1; i<n_event;i++){
				if(t == eventArr[i]){
					if_sim = 1;
					break;
				}
			}
			if(if_sim == 1){
				if_sim = 0;
			}
			else if(if_sim == 0){
				eventArr[n_event] = t;
				n_event++;
			}
		}
		for(int i = 0; i < 7;i++){
			cout<<"your event array: " << eventArr[i] << endl;
		}
	}
}
/*****************************************************
** Function: randGen()
** Author: Abhi
** Date: 05/28/2019
** Description: this generates the random set of events that will be placed on the map
******************************************************/
void Game::randGen(){
	int n_event = 1;
	int event[7];
	bool checker = false;
	int t;
	event[0] = rand () % (sizeMap*sizeMap) + 1;
	while(n_event < 7){
		t = rand() % (sizeMap*sizeMap) + 1;
		if(t == event[n_event-1]){
			checker = true;
			break;
		}
		if(checker == true){
			checker = false;
		}
		else if(checker == false){
			event[n_event] = t;
			n_event++;
		}
	}
	cout<<endl;
	ladder = event[0];
	batUno = event[1];
	batDos = event[2];
	pitUno = event[3];
	pitDos = event[4];
	wumpusUno = event[5];
	gold_1 = event[6];
	for(int i =0; i < 7;i++) {
		eventArr[i] = event[i];
	}
}


/*****************************************************
** Function: area_of_cave(int r, int c)
** Author: Abhi
** Date: 05/28/2019
** Description: bool function to see if the map area is accurate
******************************************************/
bool Game::area_of_cave(int r, int c) {
	if(r<0||r>sizeMap-1|| c<0|| c>sizeMap-1){
		return false;
	}
	else{
		return true;
	}
}

/*****************************************************
** Function: win()
** Author: Abhi
** Date: 05/28/2019
** Description: you win the game this funciton gets called
******************************************************/
int Game::win() {
	if(wumpusStatus == 1 && goldMake == 1 && identifier == eventArr[0]){
		wumpusStatus = 0;
		goldMake = 0;
		arrow = 3;
		return 1;
	}
	else{
		return 0;
	}
}
/*****************************************************
** Function: area_check()
** Author: Abhi
** Date: 05/28/2019
** Description: calls all the other area check functions
******************************************************/
void Game::area_check(){
	//int spot;
	int checker = 1;
	for(int i = 0; i<sizeMap; i++){
		for(int j= 0; j< sizeMap; j++){
			if(i == xPlane && j == yPlane){
				spot = checker;
			}
			checker++;
		}	
	}
	area_1();
	area_2();
	area_3();
	area_4();
	area_5();
}
/*****************************************************
** Function: area_#()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if the area of the cave matches with the wumpus
******************************************************/
void Game::area_5() {
	if(area_of_cave(xPlane, yPlane+1)){
		for(int i = 1; i < 6; i++){
			if(spot+1 == eventArr[5] && wumpusStatus ==1){
				cout<<"DEAD"<<endl;
				break;
			}
			if(spot + 1 == eventArr[i]){
				map[xPlane][yPlane+1]->printPercept();
			}
		}
	}
}
/*****************************************************
** Function: area_#()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if the area of the cave matches with the wumpus
******************************************************/
void Game::area_4() {
	if(area_of_cave(xPlane, yPlane-1)){
		for(int i = 1; i < 6; i++){
			if(spot-1 == eventArr[5] && wumpusStatus ==1){
				cout<<"DEAD"<<endl;
				break;
			}
			if(spot - 1 == eventArr[i]){
				map[xPlane][yPlane-1]->printPercept();
			}
		}
	}

}
/*****************************************************
** Function: area_#()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if the area of the cave matches with the wumpus
******************************************************/
void Game::area_3() {
	if(area_of_cave(xPlane+1, yPlane)){
		for(int i = 1; i < 6; i++){
			if(spot+sizeMap == eventArr[5] && wumpusStatus ==1){
				cout<<"DEAD"<<endl;
				break;
			}
			if(spot + sizeMap == eventArr[i]){
				map[xPlane+1][yPlane]->printPercept();
			}

		}
	}

}
/*****************************************************
** Function: area_#()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if the area of the cave matches with the wumpus
******************************************************/
void Game::area_2(){
	if(area_of_cave(xPlane+1, yPlane)){
		for(int i = 1; i < 6; i++){
			if(spot+sizeMap == eventArr[5] && wumpusStatus ==1){
				cout<<"DEAD"<<endl;
				break;
			}
			if(spot + sizeMap == eventArr[i]){
				map[xPlane+1][yPlane]->printPercept();
			}

		}
	}
}
/*****************************************************
** Function: area_#()
** Author: Abhi
** Date: 05/28/2019
** Description: checks if the area of the cave matches with the wumpus
******************************************************/
void Game::area_1() {
	if(area_of_cave(xPlane-1, yPlane)){
		for(int i = 1; i < 6; i++){
			if(spot-sizeMap == eventArr[5] && wumpusStatus ==1){
				cout<<"DEAD"<<endl;
				break;
			}
			if(spot - sizeMap == eventArr[i]){
				map[xPlane-1][yPlane]->printPercept();
			}
		}
	}
}
/*****************************************************
** Function: print_map()
** Author: Abhi
** Date: 05/28/2019
** Description: prints the map, pretty simple
******************************************************/
void Game::print_map(){
	cout << "+--------------------------------+" << endl;
	for(int i = 0; i<sizeMap; i++){
		//cout << "-";
		for(int j = 0; j < sizeMap; j++){
			cout << "  |  ";
			//cout << "  |  " << endl;
			if( i == xPlane && j == yPlane){
				cout<< "*";
			}
			else{
				cout<< " ";
			}
		}
		//cout << " | ";
		cout << " | " << endl;
	}
	cout << "+--------------------------------+" << endl;
}
void Game::debugDisplay() {}
/*****************************************************
** Function:start_game()
** Author: Abhi
** Date: 05/28/2019
** Description: this starts the events on the map and will be used to generate the actual items on the map
******************************************************/
void Game::start_game(){
	int place = ladder;
	for (int i = 0; i<sizeMap;i++){
		for(int j = 0; j<sizeMap;j++){
			if(place ==1){
				targetX = i;
				xPlane = i;
				yPlane= j;
				targetY=j;
			}
			place--;
		}
	}
	place = pitUno;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_pit();
			}
			place--;
		}		
	}
	place = pitDos;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_pit();
			}
			place--;
		}
	}
	place = batUno;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_bat();
			}
			place--;
		}
	}
	place = batDos;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_bat();
			}
			place--;
		}
	}
	place = wumpusUno;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_wumpus();
			}
			place--;
		}

	}
	place = gold_1;
	for(int i = 0; i < sizeMap; i++){
		for(int j = 0; j< sizeMap; j++){
			if(place ==1){
				map[i][j]->set_gold();
			}
			place--;
		}
	}
}
/*****************************************************
** Function:event_check()
** Author: Abhi
** Date: 05/28/2019
** Description: this is for each scenario on what will happen if you meet any of the creatures
******************************************************/
int Game::event_check(){
	if(identifier == eventArr[1] || identifier == eventArr[2]){
		cout<<"one of the super bat has taken you and dropped you in a random room"<<endl;
		identifier = rand() % (sizeMap * sizeMap) + 1;
		int new_spot = identifier;
		for(int i = 0; i< sizeMap; i++){
			for(int j=0;j < sizeMap; j++){
				if (new_spot == 1){
					xPlane = i;
					yPlane = j;
				}
				new_spot--;
			}
		}
		event_check();

	}
	else if(identifier == eventArr[3] || identifier == eventArr[4]){
		cout<<"You fell thorugh a pit"<<endl;
		return 0;
	}
	else if(identifier == eventArr[6]){
		if(goldMake == 1){
			return 1;
		}
		else{
			cout<<"that's cool you found gold!"<<endl;
			goldMake = 1;
		}
	}
	else if(identifier == eventArr[5]){
		if(wumpusStatus == 1){
			return 1;
		}
		else{
			cout<<"You saw a wumpus, and now you're dead"<<endl;
			arrow = 3;
			wumpusStatus=0;
			goldMake=0;
			return 0;
		}		
	}
	return 1;	
}





