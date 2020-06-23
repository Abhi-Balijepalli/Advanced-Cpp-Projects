#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
	
// this function will print out the rules to the screen
void rules() {
	cout << "Welcome to blackjack" << endl;
	cout << "the rules of blackjack are simple, you play against the dealer. you won't be able to see the dealer's cards because they are randomized, but you will be able to see your end result." << endl;
	cout << "if you reach 21 or get a higher score in the total score of your cards than the dealer you will win twice your initial bet. you play till your bank amount goes to zero and that's when the game ends. " << endl;
}
int playGame(int amtPlayers) {      //this code will execute how many players will playing in this game, it will also deal will error handling

// these variables are for the bank values of each player
	int bank1=0;
	int bank2=0;
	int bank3=0;
	int bank4=0;

// these variables symbolize each player, and show the bets
	int bet1;
	int bet2;
	int bet3;
	int bet4;

// these variables are moves (1 or 0) for each player
	int move1;
	int move2;
	int move3;
	int move4;

// these are the two outcome cards for each player, there is a 3rd card option but it is inside each if() statement for each player
	int card1;
	int card2;

// this three variables is basically the dealer, and what his outcome card is
	int dCard = int (rand()%11)+1;
	int dCard2 = int (rand()%11)+1;              
        int dFinal = (dCard + dCard2 + 7);
	
	do {                                                      // this simple do while will check how many players are playing and run each funciton.
	if (amtPlayers == 1) {
		cout << "player" << 1 << ", how much money are you starting with? ";	
		cin >> bank1;
		break;
		}
	else if (amtPlayers == 2) {
		cout << "player" << 1 << ", how much money are you starting with? ";	
		cin >> bank1;
		cout << "player" << 2 << ", how much money are you starting with? ";	
		cin >> bank2;
		break;
		}                                                                               
	else if (amtPlayers == 3) {                                                                     
		cout << "player" << 1 << ", how much money are you starting with? ";
		cin >> bank1;
		cout << "player" << 2 << ", how much money are you starting with? ";	                                                       
		cin >> bank2;
		cout << "player" << 3 << ", how much money are you starting with? ";		
		cin >> bank3;
		break;
		}                                                                           
	else if (amtPlayers == 4) {                                                                    
		cout << "player" << 1 << ", how much money are you starting with? ";
		cin >> bank1;		
		cout << "player" << 2 << ", how much money are you starting with? ";
		cin >> bank2;	
		cout << "player" << 3 << ", how much money are you starting with? ";	
		cin >> bank3;
		cout << "player" << 4 << ", how much money are you starting with? ";	
		cin >> bank4;
		break;
		}
	else {
		cout << "you entered the wrong amount, invalid input" << endl;
		exit(0);
		}
	} while(amtPlayers <= 4 && amtPlayers >= 1);

// code for 1 player ********************************************************************************************************************************
	 if(bank1 > 0) {
 		while (bank1 > 0) {
			cout << "Player1, How much do you want to bet: ";
			cin >> bet1;                                                                                          
			if (bet1 <= 0 ) {                                                                         	
                		cout << "you have entered a wrong value (invalid), so you will be kicked" << endl;
                		break;
                	}                                                                                         
			int card1 = int(rand()%11) +1;   // 1st card drawn
			cout << "(Player1) you got " << card1 <<". do you want to go again(1-yes, 0-no): " << endl;
			cin >> move1;
			do {
				int card2 = int (rand()%11)+1 + card1;		// 2nd card drawn
				if(move1 == 1) { 
					cout << "(Player1) you got " << card2 <<". do you want to go again(1-yes, 0-no): " << endl;
					cin >> move1;
					if (move1 ==1) {
						int card3 = card2 + int (rand()%11)+1 + 9;
						if (card3 <= 21 && card3 > dFinal) {
							cout << "you got a total of" <<card3<<endl;
							bank1 += bet1 *2;
							cout << "you won " << (bet1*2) << " you have a total of (press 9 if you want to cash out, or type anything else if not) " <<  bank1 << endl;
							string leave;
                                                	cin >> leave;
                                                	if(leave == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            
						}
						else if (card2 == dFinal && card2 <= 21) {
							cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet1 << endl;; 	
							string leave2;                                                 						
                                                	cin >> leave2;
                                                	if(leave2 == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            
						}
						else {
							bank1 -= bet1;
							cout << "you lost, you have " << bank1 << " left in your bank(if you want to cash out press 9, if not type anything):"<< endl;
							string leave3;
                                                	cin >> leave3;
                                                	if(leave3 == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            	
						}
					}

					else if(move1 == 0) {
						if (card2 > dFinal && card2 <= 21) {
							cout << "you got a total of" <<card2<<endl;
							bank1 += bet1 *2;
							cout << "you won " << (bet1*2) << "you have a total of (if you want to cash out press 9, if not type anything)" <<  bank1 << endl;
							string leave1;                                                 						
                                                	cin >> leave1;
                                                	if(leave1 == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            
						}
						else if (card2 == dFinal && card2 <= 21) {
							cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet1 << endl;							
							string leave2;
                                                	cin >> leave2;
                                                	if(leave2 == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            

						}
						else {
							bank1 -= bet1;
							cout << "you lost" << " you have" << bank1 << " left in your bank(if you want to cash out press 9, if not type anything)"<<endl;
							string leave3;
                                                	cin >> leave3;
                                                	if(leave3 == "9") {
                                                		cout << "bye, you have cashed out with: " << bank1;
                                                		exit(0);
                                                	}                                                            

						}                                                                                      

					}
					else {
						cout << "invalid input" << endl;             // checks for invalid inputs others than 0 or 1
						break;
					}
				}
				else if (move1 ==0) {
					if (card2 > dFinal && card2<=21) {
						bank1 += bet1*2;
						cout << "you won: " <<(bet1*2)<< "you have a total of(if you want to cash out press 9, if not type anything): "<< bank1 << endl;
						string leave;                                                 						
                                        	cin >> leave;
                                        	if(leave == "9") {
                                        		cout << "bye, you have cashed out with: " << bank1;
                                        		exit(0);
                                        	}                                                            
					} 
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet1 << endl;;
						string leave2;
                                        	cin >> leave2;
                                        	if(leave2 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank1;
                                        		exit(0);
	                                       	}                                                            
					
					} 
					else {
						bank1 -= bet1;
						cout << "you lost, and you have" << bank1 << " left in your bank(if you want to cash out press 9, if not type anything):"<< endl;
						string leave3;                                                 						
                                        	cin >> leave3;
                                        	if(leave3 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank1;
                                        		exit(0);
                                        	}                                                            
					}	
				}
				else { 
					cout << "invalid input" << endl;
					break;
				}			
			}while(card2 <= 21);                                                                                                         
		}
	 }
// code for player 2******************************************************************************************************************************	           
	while (bank2 > 0) {
		cout << "Player2, How much do you want to bet: ";
		cin >> bet2;
		if (bet2 <= 0 ) {                                                                            	
        		cout << "you have entered a wrong value (invalid), so you will be kicked" << endl;
        		break;
		}                                                                                          
		int card1 = int (rand()%11)+1;
		cout << "(Player2) you got " << card1 <<". do you want to go again(1-yes, 0-no): " << endl;
		cin >> move2;
		do {
			int card2 = card1 + 15;
			if(move2 == 1) { 
				cout << "(player2) you got " << card2 <<". do you want to go again(1-yes, 0-no): " << endl;
				cin >> move2;
				if (move2 ==1) {
					int card3 = card2 + int (rand()%11)+1;
					if (card3 <= 21 && card3 > dFinal) {
						cout << "you got a total of" <<card2<<endl;
						bank2 += bet2 *2;
						cout << "you won " << (bet2*2) << "you have a total of(if you want to cash out press 9, if not type anything): " << bank2 << endl;
						string leave1;
                                        	cin >> leave1;
                                       		if(leave1 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank2;
                                        		exit(0);
                                       		 }	                                                          
					}
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet2 << endl;; 	
						string leave2;
                                                cin >> leave2;
                                                if(leave2 == "9") {
                                                	cout << "bye, you have cashed out with: " << bank2;
                                                	exit(0);
                                                }                                                          
					}
					else {
						bank2 -= bet2;
						cout << "you lost, you have " << bank2 << " left in your bank(if you want to cash out press 9, if not type anything):"<< endl;
						string leave3;
                                                cin >> leave3;
                                                if(leave3 == "9") {
                                                	cout << "bye, you have cashed out with: " << bank2;
                                                	exit(0);
                                                }                                                          				
					}
				}
				else if(move2 == 0) {
					if (card2 > dFinal && card2 <= 21) {
						cout << "you got a total of" <<card2<<endl;
						bank2 += bet2 *2;
						cout << "you won " << (bet2*2) << "you have a total of(if you want to cash out press 9, if not type anything): " <<  bank2 << endl;
						string leave1;
                                                cin >> leave1;
                                                if(leave1 == "9") {
                                                	cout << "bye, you have cashed out with: " << bank1;
                                                	exit(0);
                                                }                                                          
					}
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything):" << bet2 << endl;	
						string leave2;
                                                cin >> leave2;
		                                if(leave2 == "9") {
			                        	cout << "bye, you have cashed out with: " << bank2;
                                                	exit(0);
                                                }                                                          
					}
					else {
						bank2 -= bet2;
						cout << "you lost" << " you have" << bank2 << " left in your bank(if you want to cash out press 9, if not type anything)"<<endl;
						string leave3;                                             			
		                                cin >> leave3;
                                                if(leave3 == "9") {
                                                	cout << "bye, you have cashed out with: " << bank3;
                                                	exit(0);
                                                }                                                          
					}                                                                                      

				}
				else {
					cout << "invalid input" << endl;
					break;
				}
			}
			else if (move2 ==0) {
				if (card2 > dFinal && card2<=21) {
					bank2 += bet2*2;
					cout << "you won: " <<(bet2*2)<< "you have a total of(if you want to cash out press 9, if not type anything):" << bank2 << endl;
					string leave2;
	                                cin >> leave2;
                                        if(leave2 == "9") {
                                        	cout << "bye, you have cashed out with: " << bank2;
                                        	exit(0);
                                        }                                                          
				} 
				else if (card2 == dFinal && card2 <= 21) {
					cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything):" << bet2 << endl;;
					string leave3;
					cin >> leave3;
                                        if(leave3 == "9") {
                                        	cout << "bye, you have cashed out with: " << bank2;
                                        	exit(0);
                                        }                                                          
				} 
				else {
					bank2 -= bet2;
					cout << "you lost, and you have" << bank2 << " left in your bank(if you want to cash out press 9, if not type anything)"<< endl;
					string leave3;
                                        cin >> leave3;
                                        if(leave3 == "9") {
                                        	cout << "bye, you have cashed out with: " << bank2;
                                        	exit(0);
                                        }                                                          
				}	
			}                                                                                                                 
			else {                                                                                                            
				cout << "invalid input" << endl;                                                                          
				break;                                                                                                    
			}			                                                                                          
		}while(card2 <= 21);                                                                                                        

	}                                                                                                                                                 
// code of player 3 ****************************************************************************************************************************************
	while (bank3 > 0) {
		cout << "(Player3) How much do you want to bet: ";
		cin >> bet3;
		if (bet3 <= 0 ) {
			cout << "you have entered a wrong value (invalid), so you will be kicked" << endl;
			break;
		}                                                                                           
		int card1 = int (rand()%11)+1;
		cout << "(Player3) you got " << card1 <<". do you want to go again(1-yes, 0-no): " << endl;
		cin >> move3;
		do {
			int card2 = card1 + 15;
			if(move3 == 1) { 
				cout << "(player3) you got " << card2 <<". do you want to go again(1-yes, 0-no): " << endl;
				cin >> move3;
				if (move3 ==1) {
					int card3 = card2 + int (rand()%11)+1;
					if (card3 <= 21 && card3 > dFinal) {
						cout << "you got a total of" <<card2<<endl;
						bank3 += bet3*2;
						cout << "you won " << (bet3*2) << "you have a total of(if you want to cash out press 9, if not type anything)" << bank3 << endl;
						string leave1;
                                        	cin >> leave1;
                                        	if(leave1 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
						}                                                           
					 }
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money (if you want to cash out press 9, if not type anything): " << bet3 << endl;; 	
						string leave2;
                                        	cin >> leave2;
                                        	if(leave2 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
                                        	}                                                         
					}
					else {
						bank3 -= bet3;
						cout << "you lost, you have " << bank3 << " left in your bank(if you want to cash out press 9, if not type anything):"<< endl;
						string leave3;
                                        	cin >> leave3;
                                        	if(leave3 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
                                        	}                                                            
					}
				}
				else if(move3 == 0) {
					if (card2 > dFinal && card2 <= 21) {
						cout << "you got a total of" <<card2<<endl;
						bank3 += bet3 *2;
						cout << "you won " << (bet3*2) << "you have a total of(if you want to cash out press 9, if not type anything): " << bank3 << endl;
						string leave1;
	                                	cin >> leave1;
		                        	if(leave1 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
                                        	}                                                            
					}
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet3 << endl;	
						string leave2;
                                        	cin >> leave2;
                                        	if(leave2 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
                                        	}                                                            
					}
					else {
						bank3 -= bet3;
						cout << "you lost" << " you have" << bank3 << " left in your bank(if you want to cash out press 9, if not type anything):"<<endl;
						string leave3;
                                        	cin >> leave3;
                                        	if(leave3 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank3;
                                        		exit(0);
                                        	}                                                            
					}                                                                                      

				}
				else {
					cout << "invalid input" << endl;
					break;
				}
			}
			else if (move3 ==0) {
				if (card2 > dFinal && card2<=21) {
					bank3 += bet3*3;
					cout << "you won: " <<(bet3*2)<< " you have a total of(if you want to cash out press 9, if not type anything): "<< bank3 << endl;
                                	string leave1;
                                	cin >> leave1;
                                	if(leave1 == "9") {                                         
                                		cout << "bye, you have cashed out with: " << bank3;
                                	}                                                                         

				}                 
                         
				else if (card2 == dFinal && card2 <= 21) {
					cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet3 << endl;
					string leave2;
                                	cin >> leave2;
                                	if(leave2 == "9") {                                         
                                		cout << "bye, you have cashed out with: " << bank3;
                                	}                                                                                 
				} 
				else {
					bank3 -= bet3;
					cout << "you lost, and you have" << bank3 << " left in your bank(if you want to cash out press 9 or type anything if not): "<< endl;
					string leave3;
                                	cin >> leave3;
                                	if(leave3 == "9") {                                         
                                		cout << "bye, you have cashed out with: " << bank3;
                                	}                                                               
				}	
			}                                                                                                                 
			else {                                                                                                            
				cout << "invalid input" << endl;                                                                          
				break;                                                                                                    
			}			                                                                                          
		}while(card2 < 22);                                                                                                        

	}                                                                                                                                      
//code player 4 *************************************************************************************************************************************************************
	while (bank4 > 0) {
		cout << "(Player4) How much do you want to bet: ";
		cin >> bet4;
		if (bet4 <= 0 ) {
			cout << "you have entered a wrong value (invalid), so you will be kicked" << endl;
			break;
		}                                                                                           
		int card1 = int (rand()%11)+1;
		cout << "(Player4) you got " << card1 <<". do you want to go again(1-yes, 0-no): " << endl;
		cin >> move4;
		do {
			int card2 = card1 + 15;
			if(move4 == 1) { 
				cout << "(player4) you got " << card2 <<". do you want to go again(1-yes, 0-no): " << endl;
				cin >> move4;
				if (move4 ==1) {
					int card3 = card2 + int (rand()%11)+1;
					if (card3 <= 21 && card3 > dFinal) {
						cout << "you got a total of" <<card2<<endl;
						bank4 += bet4 *2;
						cout << "you won " << (bet4*2) << "you have a total of(if you want to cash out press 9, if not type anything):" << bank4 << endl;
						string leave1;
                                        	cin >> leave1;
                                        	if(leave1 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
                                        	}                                                            
					}
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet4 << endl;; 	
						string leave2;
                                        	cin >> leave2;
                                        	if(leave2 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
                                        	}                                                            
					}
					else {
						bank4 -= bet4;
						cout << "you lost, you have " << bank4 << " left in your bank (if you want to cash out press 9, if not type anything): "<< endl;
						string leave3;
                                        	cin >> leave3;
                                        	if(leave3 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
                                        	}                                                            

					}
				}
				else if(move4 == 0) {
					if (card2 > dFinal && card2 <= 21) {
						cout << "you got a total of" <<card2<<endl;
						bank4 += bet4*2;
						cout << "you won " << (bet4*2) << "you have a total of(if you want to cash out press 9, if not type anything):" << bank4 << endl;
						string leave1;
                                        	cin >> leave1;
                                        	if(leave1 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
						}          
                                        }
					else if (card2 == dFinal && card2 <= 21) {
						cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet4 << endl;	
						string leave2;
                                        	cin >> leave2;
                                        	if(leave2 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
                                        	}                                                            
					}
					else {
						bank4 -= bet4;
						cout << "you lost you have" << bank4 << " left in your bank(if you want to cash out press 9, if not type anything)"<<endl;
						string leave3;
                                        	cin >> leave3;
                                        	if(leave3 == "9") {
                                        		cout << "bye, you have cashed out with: " << bank4;
                                        		exit(0);
                                        	}                                                            
					}                                                                                      

				}
				else {
					cout << "invalid input" << endl;
					break;
				}
			}
			else if (move4 ==0) {
				if (card2 > dFinal && card2<=21) {
					bank4 += bet4*2;
					cout << "you won: " <<(bet4*2)<< "you have a total of(if you want to cash out press 9, if not type anything: "<< bank4 << endl;
					string leave1;
                			cin >> leave1;
                			if(leave1 == "9") {
                				cout << "bye, you have cashed out with: " << bank4;
                				exit(0);
					}                       
                                } 
				else if (card2 == dFinal && card2 <= 21) {
					cout << "you tied with the dealer, here is your money(if you want to cash out press 9, if not type anything): " << bet4 << endl;;
					string leave2;
					cin >> leave2;
					if(leave2 == "9") {
						cout << "bye, you have cashed out with: " << bank4;
						exit(0);
					}                                                               
					
				} 
				else {
					bank4 -= bet4;
					cout << "you lost, and you have" << bank4 << " left in your bank( if you want to cash out press 9, if not type anything): "<< endl;
					string leave3;
                                	cin >> leave3;
                                	if(leave3 == "9") {
                                		cout << "bye, you have cashed out with: " << bank4;
                                		exit(0);
                                	}                                                            
				}	
			}                                                                                                                 
			else {                                                                                                            
				cout << "invalid input" << endl;                                                                          
				break;                                                                                                    
			}			                                                                                          
		}while(card2 < 22);                                                                                                        

	}                                                                                                                                      

}
      
int main() {
	int amt; 
        rules();
	while(true) { // this will reloop the game at the end.
		cout << "How many people are playing (1-4): ";
		cin >> amt;
		playGame(amt);   // amt is the amount of players, and it will be replacing the parameters in the playGame method.
		string quit;
		cout << " " << endl;
		cout << "type yeet to repeat or anything else to quit: ";
		cin >> quit;
		if (quit != "yeet") {
			break;
		}
	}	
	return 0; 
}                                        
