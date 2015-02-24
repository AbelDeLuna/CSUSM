// =========================================================
//HW1P2 vector stack
//Your name: Abel De Luna
//Complier:  g++
//File type: vector.cpp file
//================================================================
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{

}

// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
{
    stack::clearIt();
}

// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()//empty means that aren't ANY values in the stack.
{
    if (myStack.empty())
        return true;
    else
        return false;
}

// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()//"full" means that it  has reached the max size of the array
{
    return false;  //this vector will never be full
}

// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
    if (isFull())
        throw Overflow();
    else
    {
        myStack.push_back(elem);
    }
}

	// ** pop calls isEmpty and if true, throws an exception (Underflow)
	//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
    {
        elem = myStack.back();
        myStack.pop_back();
    }
}

	// ** topElem calls isEmpty and if true, throws an exception (underflow)
	//    Otherwise, gives back the front element from el_t.
void stack::topElem(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
    {
        elem = myStack.front();
    }
 }

	//dislayAll calls isEmpty and if true, displays error message.
	//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    if (isEmpty())
        cout << "There are no elements." << endl;
    else
        for (int i=myStack.size(); i>=0; i--)
        {
            cout << myStack[i] << endl;
        }
}
	//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
    cout << "running clearit.";
    if (isEmpty()) // if the stack is already empty, it will throw an underfloww message.
        exit(1);
    else
    {
      el_t out;
      while (!myStack.empty())// the While loop will pop each element and remove it from the stack
      {
        pop(out);// call the pop function to start removing
      }
    }
}
