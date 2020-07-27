/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#ifndef __FUNCTION__H__
#define __FUNCTION__H__
#include "decoration.h"

class function : decoration {
    private:
    char  id [20]; // user id
    char  name[20]; // user name
    char  lastName[20]; // user lastname
    float sum; // user balance
    unsigned x; // deposite or withdraw

    public:
    void create(); // create account
    void deposit(); // deposite +
    void withdraw(); // withdraw -
    void all();
    
};


#endif  //!__FUNCTION__H__