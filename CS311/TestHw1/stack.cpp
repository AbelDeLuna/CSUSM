// =========================================================
//HW1P1 stack
//Your name: Abel De Luna
//Complier:  g++
//File type: stack.cpp file
//================================================================
#include <iostream>
#include <string>

using namespace std;

#include "stack.h"

//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{
    top = -1; // indicate an empty stack
}

// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
{
}

// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()//empty means that aren't ANY values in the stack.
{
    if (top == -1)
        return true;
    else return false;
}

// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()//"full" means that it  has reached the max size of the array
{
    if (top == MAX-1 )
        return true;
    else return false;
}

// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
    if (isFull())
        throw Overflow();
    else { top++; el[top] = elem; }
}

	// ** pop calls isEmpty and if true, throws an exception (Underflow)
	//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
    {
        elem = el[top]; top--;
    }
}

	// ** topElem calls isEmpty and if true, throws an exception (underflow)
	//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else { elem = el[top]; }
 }

	//dislayAll calls isEmpty and if true, displays error message.
	//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    if (isEmpty())
        cout << "There are no elements." << endl;
    else
        for (int i=top; i>=0; i--)
        {
            cout << el[i] << endl;
        }
}
	//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
    if (isEmpty()) // if the stack is already empty, it will throw an underfloww message.
        throw Underflow();//
    else
    {
      el_t out;
      while (top != -1)// the While loop will pop each element and remove it from the stack
      {
        pop(out);// call the pop function to start removing
        top--;
      }
    }
}
