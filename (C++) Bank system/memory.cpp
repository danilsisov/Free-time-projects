/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/
#include "memory.h"
#include "function.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<iomanip>
using namespace std;



// add and save account to file bank.txt
void bank::new_in() {
    ofstream outfile;
    outfile.open("bank.txt", ios::app| ios::binary);
    create();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}

// read from file
void bank::read_rec() {
    ifstream infile; // Stream class to read from files
    infile.open("bank.txt", ios::binary);// open file (bank.txt) in binary mode to write and read from file


    //If file can not to open
    if(!infile) {
        cout << "Error! Try again" << endl;
        return;
    }

    // file open
 
    cout <<"\n\n\t\t\tALL ACCOUNT DATA" << endl;

    while(!infile.eof()) { //read while file have symbols
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            all(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
    infile.close(); // close file
}

void bank::search_rec() {
    cout <<"\n\n\t\t\tFind your account" << endl;
    int n; // choose account 
    ifstream in_search; // Stream class to read from files
    in_search.open("bank.txt", ios::binary); // open file (bank.txt) in binary mode to write and read from file

    //ERROR
    if(!in_search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    in_search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int count = in_search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Enter your ID number to find your personal data: ";
    cin >> n;
    in_search.seekg((n-1)*sizeof(*this)); // find account what user need
    in_search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    all(); // tempalte for accounts
    cout << endl;
    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

void bank::edit_deposite() {
    cout <<"\n\n\t\t\tDeposite" << endl;
    int n;
    fstream indep;
    indep.open("bank.txt", ios::in|ios::binary); // open file in binary mode and for input mode

    //ERROR
    if(!indep) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    indep.seekg(0, ios::end); // Go to end of input file
    int count = indep.tellg()/sizeof(*this);  //Returns the position of the current character in the input stream.
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    indep.seekg((n-1)*sizeof(*this)); // find account what user need
    indep.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    cout << "Record " << n << " has following data" << endl;
    all();
    indep.close();
    indep.open("bank.txt", ios::out|ios::in|ios::binary); // // open file in binary mode, for input mode and reading mode
    indep.seekp((n-1)*sizeof(*this)); //Sets the position where the next character is to be inserted into the output stream
    // open void deposite() for deposite
    deposit();
    indep.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void bank::edit_withdraw() {
    cout <<"\n\n\t\t\tWithdraw" << endl;
    int n;
    fstream inwithdr;
    inwithdr.open("bank.txt", ios::in|ios::binary);

    if(!inwithdr) {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    inwithdr.seekg(0, ios::end);
    int count = inwithdr.tellg()/sizeof(*this);
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    inwithdr.seekg((n-1)*sizeof(*this));
    inwithdr.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    all();
    inwithdr.close();
    inwithdr.open("bank.txt", ios::out|ios::in|ios::binary);
    inwithdr.seekp((n-1)*sizeof(*this));
    withdraw();
    inwithdr.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void bank::delete_rec() {
    cout <<"\n\n\t\t\tDELETE" << endl;
    int n;
    ifstream infile;
    infile.open("bank.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("file.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("bank.txt");
    rename("file.txt", "bank.txt");
}
