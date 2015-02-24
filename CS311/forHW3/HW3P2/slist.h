#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include "llist.h"
using namespace std;


class slist: public llist
{
    public:
        slist();
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
