//HW3P1 llist
//Your name: Abel De Luna
//Complier:  g++
//File type: llist.cpp
//=====================================================
#include <iostream>
#include "llist.h"

using namespace std;

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
    Front = NULL;
    Rear = NULL;
    Count = 0;
}
//Destructor
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  cout << "llist destructor!"<< endl;
    el_t x;
    while (!isEmpty())
      {cout << "preparing to delete front" << endl;
        deleteFront(x);
	  cout << "deleted front" << endl;}
      cout << "de done" << endl;
      
}
//boolean isEmpty()
//- return true if Front and Rear are both pointing to NULL.
//- (note: do not use Count for this!!!)
bool llist::isEmpty()
{
    if (Front == NULL && Rear == NULL && Count == 0)
        {return true;}
    else
        return false;
}
void llist::displayAll()
//- displays each element of the list starting from Front in [ ].
//- (special case: if the list is empty, display [ empty ] ).
{
    if (isEmpty()) // test if list is empty
        {cout << "[Empty]" << endl;}

    else
    {
        P = Front;
        while (P != NULL) //runs curr pointer through everything and prints it
        {
            cout << "[ " << P->Elem << " ] ";
            P = P->Next;
        }
        cout << Count << endl;
    }
}
void llist::addRear(el_t NewNum)
//- 2 cases
//- adds a new node at the rear and puts NewNum in the Elem field
//  of this new node. Count is updated.
//- (special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it.)
{
    if (isEmpty()) // special case if list is empty
    {
        addFront(NewNum);
    }
    //Regular case:
    else
    {
        Rear->Next = new Node;
        Rear = Rear->Next;
        Rear->Elem = NewNum;
        Rear->Next = NULL;
        Count++;
    }
}
void llist::deleteFront(el_t& OldNum)
//- 3 cases
//-  error case: if the List is empty, throw an exception.
//-  else give back the front node element through OldNum (pass by reference)
//   and also remove the front node. Count is updated.
//-  (special case: if this is going to make the list empty,
//    make sure both Front and Rear become NULL).
{
    if (isEmpty())
    {
        throw Underflow();
    }
    //Regular case:
    else
    {
        OldNum = Front->Elem;
        Node *Second;
        Second = Front->Next;
        delete Front;
        Front = Second;
        Count--;
    }

    if (isEmpty()) //special case if list is now empty
    {
        Front = NULL;
        Rear = NULL;
    }
}
void llist::addFront(el_t NewNum)
//- 2 cases
//- will add a new node to the front of the list. Count is updated.
//- (special case: if this is going to be the very first node, you must
//  create a new node and make Front and Rear point to it.)
{
    if (isEmpty())//special case if first node
    {
        Front = new Node;
        Front->Next = Rear;
        Front->Elem = NewNum;
        Rear = Front;
        Rear->Next = NULL;
    }
    else //Regular case:
    {
        Node *x;
        x = new Node;
        x->Next = Front;
        Front = x;
        Front->Elem = NewNum;
    }
    Count++;
}
void llist::deleteRear(el_t& OldNum)
//- 3 cases
//- error case: if empty, throw an exception.
//- else give back the rear node element through OldNum (pass by reference)
//  and also remove the rear node. Count is updated.
//- (special case: if this is going to make the list empty,
//   make sure both Front and Rear become NULL).
{
    if (isEmpty())
    {
        throw Underflow();
    }
    else//Regular case:
    {
        OldNum = Rear->Elem;
        Node *p;
        p = Front;
        //Make p go to the one right before rear (using while)
        while (p->Next != Rear)
        {
            p = p->Next;
        }
        delete Rear;
        Rear = p;
        Count--;

        if (isEmpty())
        {
            Front = NULL;
            Rear = NULL;
        }
    }
}
void llist::deleteIth(int I, el_t& OldNum)
//- 4 cases
//- will delete the Ith node (I starts out at 1).  Count is updated.
//- Error cases:
//  If I is an illegal value (i.e. > Count or < 1) throw an exception.
//- (note: this may simply call deleteFront or deleteRear for some cases)
{
    if (isEmpty())
        throw Underflow();

    else if (I == 1)
        deleteFront(OldNum);

    else if (I == Count)
        deleteRear(OldNum);

    else
    {
        int i = 1;
        Node *X = Front;
        Node *Y;
        while (i != I)
        {
            Y = X;
            X = X->Next;
            i++;
        }
        Y->Next = X->Next;
        delete X;
    }
    Count--;
}
void llist::addbeforeIth(int I, el_t newNum)
//- 4 cases
//-  will add right before the Ith node.  Count is updated.
//-  Error cases:
//   If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
//-  (note: this may simply call addFront or addRear for some cases)
{
    if (I > Count+1 || I < 1)
        throw OutOfRange();

    else if (I == 1)
        addFront(newNum);

    else if (I==Count)
        addRear(newNum);

    else
    {
        int i = 1;
        Node *X = Front; //X pointer = Front
        Node *Y; //pointer to act as X->prev
        Node *Z = new Node; //Location of new number
        Z->Elem = newNum;
        while (i != I) //run until X = I and Y->Next = I
        {
            Y = X;
            X = X->Next;
            i++;
        }
        Y->Next = Z;
        Z->Next = X;
        Count++;
    }

}


