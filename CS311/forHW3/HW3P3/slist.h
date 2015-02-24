#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include "llist.h"
using namespace std;

// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference

class slist: public llist
{
    public:
        slist();
	  // ~slist();
        slist& operator=(const slist& OtherOne); // overloaded assignment operator
        slist(const slist& Original); //copy constructor
        bool operator==(const slist& OtherOne); // overloaded equality-test operator
        int search(el_t key);
        void replace(el_t Elem, int I);
    protected:
    //Node *Front;       // front  pointer
    //Node *Rear;        // rear   pointer
    //Node *P;
    //int  Count;        // counter for the number of elements
    private:
};

#endif // SLIST_H
