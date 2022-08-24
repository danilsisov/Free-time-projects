/******************************************************************************
DANIL SISOV
GUEESS NUMBER GAME
2K20
                          
*******************************************************************************/

#include "RE.h"
#include <cstdlib> // for random

using namespace std;

// third screen with name and amout of money
void game::deposit() {
    cout << "\t\t\tDEPOSIT\n";
    cout << "\nEnter Your Name : ";
    getline(cin, playerName); // string name
    cout << "Enter Deposit amount to play game : $";
    cin >> sum;
    
    //while amount < 0
    if (sum < 0) {
        cout << "Error, try again" << endl;
        return end();
    }
    
    line(); // line
    startPlay_logo(); //return to logo 
 }
 
// start play with current balance
void game::startPlay_logo() {
    cout << "\n";
    cout << "\t\t\tGUESS NUMBER\n";
    cout << "\nYour current balance is $ " << sum << "\n";
    return startPlay();
}

// main function (amout to bet, Choose number, random generator, result)
void game::startPlay() {
do {
    cout << playerName<<", enter money to bet: $";
    cin >> bet;
    
    if (bet > sum) {
        cout << "Error, try again\n" << endl;
        return startPlay();
    }
    
    else if (bet <= sum) {
        cout << "Choose number since 1 to 10:  ";
        cin >> user_num;
        
        if ((user_num <= 0)||(user_num > 10))
        cout <<"\nRe-enter data\n "<<endl;      
    }       
} 

while ( user_num <= 0 || user_num > 10 );

random = rand()%10 + 1; // random generator
 
 if (random == user_num) {
     cout << endl;
     cout << "Result:" <<endl;
     cout << "Correct answer is - " << random << endl;
     cout << "Victory you did it, your answer was correct" << endl;
     cout << "You won $" << bet * 10 <<endl;
     sum = sum + bet * 10; // win sum
     line();
     cout << endl;
     cout << "Your total bank is $" << sum << endl;
     cin.get(); // freeeze
     return again();
 } 
 else {
     cout << endl;
     cout << "Result:" <<endl;
     cout << "Correct answer is - " << random << endl;
     cout << "You lose $" << bet << endl;
     sum = sum - bet;
     start();
     cout << endl;
     cout << "Your total bank is $" << sum << endl;
     cin.get(); //freeze
     return again();
     }
  }
  
// last screen function with question (play again)
void game::again() {
    if (sum == 0) {
        return end();
    }
    cout << "\n---->Do you want to play again (y/n)? ";		
    cin >> choice;
    line(); //line
    cout << endl;
    if (choice =='Y'|| choice=='y') {
        return startPlay ();
    }
    else {
        return end();
    }

}
// end of programm 
void game::end(){
    cout << "\nThanks for playing game. Your balance amount is $ " << sum << "\n\n";
    }
