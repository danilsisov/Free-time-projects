#include "prog.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//Start logo
     void calender::start(){
        cout << "____________________lEAP OR NOT?____________________" << endl;
     }
     //First qustion
     void calender::info () {
        cout << "\n";
        cout << "Type a year to find out a leap year or not - "; 
        cin >> year;
        return check();
    }    
     
     void calender::check () {
     //error if year less than 1
        while (year < 0 || year == 0) {
            cout << "Sorry, try to type new year" << endl;
            return info();
    }
    //check leap or not with formula
    // Leap year
       if ((year % 100 == 0) && (year & 400 == 0) || (year % 4 == 0)) { 
           cout << "\n";
           cout << "Answer:  " <<  year << " year have 29 days, so it is a leap year" << endl;
           cout << "--------------------------------------------"<< endl;  
           cout << ""<< endl; 
    }
      else {
      //not leap year
           cout << "\n";
           cout << "Answer:  " <<  year << " year have 28 days, it is not a leap year"<< endl;
           cout << "--------------------------------------------"<< endl;  
           cout << ""<< endl; 
   }
   // way to next section. Choose exit or continue
   return again();
}
   //choose way. One for exit. One for more years     
   void calender::again () {
       cout << "More dates - press 1"<< endl;
       cout << "Exit - press 2" << endl;
       cout << "your selection: ";
       cin >> menu;
       cout << "--------------------------------------------"<< endl;  
       cout << ""<< endl; 
       
        if (menu == 1) { 
           return info();
       }
        else if (menu == 2) {
               cout << "Exit....." << endl;
       }
       //Error, if number is not 1 or 2
        else {
            cout << "Try to choose only 1 or 2" << endl;
            return again();
        }
    }
