/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#include "decoration.h"
#include "iostream"
using std::cout;
using std::endl;
using std::cin;


void decoration::line() {
for (int i = 0; i < amount; i++) {
    cout << symb;
    }
}

void decoration::author(){
    line();
        cout << "\n\n\t\t\t\t BANK SYSTEM" << endl;
        cout << "\t\t\t\t     by" << endl;
        cout << "\t\t\t\t©Danil Sisov\n" << endl;
    
        line(); //line
        cin.get(); //freeze
        return rules();
}

void decoration::rules() {
    cout << "\n";
    cout << "\t\t\tRULES OF THE GAME\n";
    cout << "\t 1. Create your account\n";
    cout << "\t 2. Make deposite\n";
    cout << "\t 3. Be happy\n";
    cout << "\t 4. Use your bank\n\n";
}

//end of decoration.cpp
