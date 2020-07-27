/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/
#include <iostream>
#include "menu.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;


void menu::screen () {
        cout<<"\n\n\t\t\t\t  MAIN MENU"; 
		cout<<"\n\n\t01| ⊚ NEW ACCOUNT"; 
		cout<<"\n\n\t02| ⊚ ALL ACCOUNT HOLDER LIST"; 
        cout<<"\n\n\t03| ⊚ DEPOSITE"; 
		cout<<"\n\n\t04| ⊚ WITHDRAW";  
		cout<<"\n\n\t05| ⊚ SERACH RECORD"; 
		cout<<"\n\n\t06| ⊚ DELETE ACCOUNT";
		cout<<"\n\n\t07| ⊚ EXIT";
        cout<<"\n\n\tSelect Your Option (1-7)⇨ ";
        cin >> option;

        switch(option)
        {
        case 1:
            new_in();
            break;
        case 2:
            read_rec();
            break;
        case 3:
            edit_deposite();
            break;
        case 4:
            edit_withdraw();
            break;
        case 5:
            search_rec();
            break;
        case 6:
            delete_rec();
            break;
        case 7:
            cout << "\n\nThank you for using our bank. Have a nice day ☻☺\n\n" << endl;
            exit(0);
            break;
        default:
            cout<<"\nIncorrect number, please type number from 1 to 7 " << endl;
            cin.get();
            return screen();
        }
    }