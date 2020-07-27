/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#ifndef __MEMORY__H__
#define __MEMORY__H__
#include "function.h"
class bank : public function {
    private:
        int n;
    
    public:
        void edit_deposite(); // deposite + to file
        void edit_withdraw(); // withdraw - to file
        void new_in(); // new account to file
        void read_rec(); //show all accounts from file with template
        void search_rec(); // search account in file
        void delete_rec(); // delete account from file
};

#endif  //!__MEMORY__H__