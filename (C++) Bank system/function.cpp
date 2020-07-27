/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#include "function.h"
#include "iostream"
using std::cout;
using std::endl;
using std::cin;

// create account 
    void function::create() {
    line();

    cout << "\nEnter Account Number: ";
    cin  >> id;
    cout << "Enter First Name: ";
    cin  >> name;
    cout << "Enter Last Name: ";
    cin  >> lastName;
    cout << "Enter Balance: $";
    cin  >> sum;
    cout << endl;
}

//all accounts list
void function::all() {
    cout << endl;
    cout << "Account Number: "<< id << endl;
    cout << "First Name: " << name << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Current Balance: $" << sum << endl;
    line();
}

//deposite +
void function::deposit() {
    cout << endl;
    cout << "Enter data to deposite: $ ";
    cin >> x;
    sum+=x;
}

//withdraw -
void function::withdraw() {
    cout << endl;
    cout << "Enter data to withdraw: $ ";
    cin >> x;
    sum-=x;
}