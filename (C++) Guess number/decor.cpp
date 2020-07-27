#include "decor.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void start::line(){
    amount = 50;
    symb = '-';

    for (int i = 0; i < amount; i++) {
    cout << symb;
    }
}

void start::author() {
     cout <<"\n\t\t\t\tGUESS NUMBER" << endl;
    cout << "\t\t\t\t  game by" << endl;
    cout << "\t\t\t\t©Danil Sisov\n" << endl;
    
    start(); //line
    cin.get(); //freeze
    return rules();
}

void start::rules() {
    cout << "\n";
    line();
    cout << "\n";
    cout << "\t\t\tRULES OF THE GAME\n";
    cout << "\t 1. Choose any number between 1 to 10\n";
    cout << "\t 2. If you win you will get 10 times of money you bet\n";
    cout << "\t 3. If you bet on wrong number you will lose your betting amount\n\n";
    
    line(); //line
    cin.get(); //freeze
}
