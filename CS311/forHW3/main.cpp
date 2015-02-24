//Title: HW3p1
//Name: Abel De Luna
//File Type: main.cpp
#include <iostream>
#include "llist.h"

using namespace std;

int main()
{
    llist ll;
    int CaseNumber;
    string msg1 = "Error: Value inputed is out of range.";
    string msg2 = "Error: Underflow. Link list is empty";
    el_t x;

cout << "Which case number to test (1-4)?: ";
    cin >> CaseNumber;

    switch (CaseNumber)
    {
    case 1:
        cout << ll.isEmpty() << endl;
        ll.displayAll();
        cout << "Made it over here";
        ll.addRear('1');
        ll.addRear('2');
        ll.addRear('3');
        ll.displayAll();
        //ll.deleteFront(x);
        //ll.deleteFront(x);
        //ll.displayAll();
        //ll.isEmpty();
        //ll.deleteFront(x);
        //ll.isEmpty();
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
        {ll.deleteIth(2,x);} //Error out of range
            catch (llist::OutOfRange)
            {
                cout << msg1 << endl;
            }
        try
        {ll.deleteRear(x);} //Error underflow
            catch (llist::Underflow)
            {
                cout << msg2 << endl;
            }
        break;
    default:
        cout << "What happened?" << endl;
        break;
    }

    return 0;
}
