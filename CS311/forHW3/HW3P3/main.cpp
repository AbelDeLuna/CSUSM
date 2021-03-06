//Title: HW3p2
//Name: Abel De Luna
//File Type: main.cpp
#include <iostream>
//#include "llist.h"
#include "slist.h"

using namespace std;

//int main();
void CopyTest(slist ListCopy);

int main()
{
    llist ll;
    slist sl;

    int CaseNumber;
    string msg1 = "Error: Value inputed is out of range.";
    string msg2 = "Error: Underflow. Link list is empty";
    el_t x;

    cout << "Which case number to test (1-4 for HW3p1, 5 for HW3p2)?: ";
    cin >> CaseNumber;

    switch (CaseNumber)
    {
    case 1:
        cout << ll.isEmpty() << endl;
        ll.displayAll();
        ll.addRear('1');
        ll.addRear('2');
        ll.addRear('3');
        ll.displayAll();
        ll.deleteFront(x);
        ll.deleteFront(x);
        ll.displayAll();
        ll.isEmpty();
        ll.deleteFront(x);
        ll.isEmpty();
        break;
    case 2:
        ll.addFront('5');
        ll.addFront('4');
        ll.deleteFront(x);
        ll.addRear('6');
        ll.addRear('8');
        ll.addRear('9');
        ll.displayAll();
        ll.addbeforeIth(1, '4');
        ll.addbeforeIth(4, '7');
        ll.addbeforeIth(7, '10');
        try
        {ll.addbeforeIth(9, '12');} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        try
        {ll.addbeforeIth(0 ,'0');} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        ll.displayAll();
        ll.deleteIth(1, x);
        ll.deleteIth(6, x);
        ll.deleteIth(3, x);
        try
        {ll.deleteIth(5, x);} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        try
        {ll.deleteIth(0, x);} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        ll.displayAll();
        while (!ll.isEmpty())  //delete rear until empty
        {
            ll.deleteRear(x);
        }
        ll.displayAll();
        break;
    case 3:
        try
        {ll.addbeforeIth(0, '0');} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        try
        {ll.deleteFront(x);} //Error underflow
            catch (llist::Underflow)
            {
                cout << msg2 << endl;
            }
        break;
    case 4:
        try
        {ll.deleteIth(2,x);} //Underflow
            catch (llist::Underflow)
            {
                cout << msg2 << endl;
            }
        try
        {ll.deleteRear(x);} //Error underflow
            catch (llist::Underflow)
            {
                cout << msg2 << endl;
            }
        break;
    case 5:
        sl.addFront('4');
        sl.addRear('6');
        sl.addRear('7');
        sl.addRear('8');
        sl.displayAll();
        int r = sl.search('6');
        cout << "r: " << r << endl;
        sl.replace('0', r);
        r = sl.search('8');
        sl.replace('2', r);
        sl.displayAll();
        try
            {sl.search('5');}
                catch (slist::Underflow)
                {
                    cout << msg1 << endl;
                }
        cout << "made it here" << endl;
        break;
    case 6:
            cout << "made it to case 6" << endl;
            slist L1;
            L1 = slist();
            cout << "slist created" << endl;
            L1.addRear('1');
            L1.addRear('2');
            L1.addRear('3');
            L1.addRear('4');
            L1.addRear('5');
            cout << "numbers added" << endl;
            CopyTest(L1);
            L1.displayAll();
            L1 = L1;
            L1.displayAll();

            slist L2;
            L2 = slist();
            L2.addRear('7');
            L2.addRear('8');
            L2.addRear('9');
            L2.addRear('10');
            L2.displayAll();

            L2 = L1;
            L2.displayAll();

            L1.deleteRear(x);
            L1.displayAll();
            L1.displayAll();
            L2.displayAll();
        break;
    default:
        cout << "What happened?" << endl;
        break;
    }

    return 0;
}

void CopyTest(slist ListCopy)
{
    ListCopy.addRear(6);
    ListCopy.displayAll();
}
