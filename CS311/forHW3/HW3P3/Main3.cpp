#include <iostream>
#include "slist.h"
using namespace std;

void CopyTest(slist ListCopy);

int main()
{
    slist L1;
    cout << "slist created" << endl;
    L1.addRear('1');
    L1.addRear('2');
    L1.addRear('3');
    L1.addRear('4');
    L1.addRear('5');
    L1.displayAll();
    cout << "L1 numbers added" << endl;
    CopyTest(L1);
    cout << "finished copytest" << endl;
    L1.displayAll();
    L1 = L1;
    L1.displayAll();

    slist L2;
    L2.addRear('7');
    L2.addRear('8');
    L2.addRear('9');
    L2.addRear('10');
    cout << "L2 numbers added" << endl;
    L2.displayAll();

    L2 = L1;
    cout << "L2 = L1" << endl;
    L2.displayAll();

    el_t x;
    L1.deleteRear(x);
    L1.displayAll();
    L1.displayAll();
    L2.displayAll();

    return 0;
}

void CopyTest(slist ListCopy)
{
    ListCopy.addRear('6');
    ListCopy.displayAll();
    cout << "Test123" << endl;
}
