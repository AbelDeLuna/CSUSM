// =======================================================
// HW1P1
// Your name: Abel De Luna
// Compiler:  g++
// File type: header file stack.h

//=======================================================
//#include <iostream>
//#include <string>
//#include <cmath>

using namespace std;

const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef int el_t;      // the el_t type is int
                      // el_t is unknown to the client

class stack
  {
   private: // to be hidden from the client

        el_t     el[MAX];       // el is  an array of el_t's
        int      top;           // top is index to the top of stack

   public: // prototypes to be used by the client

        // exception handling classes
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL:
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

       //HOW TO CALL:Simply call the function. Nothing is called for from this method
       //Purpose: To check if the stack is empty and return a true or false
      	bool isEmpty();

      	//How to call: Simply call the function. Nothing needs to be sent
      	//Purpose: To check if the stack is at capacity. Returns a true or false
      	bool isFull();

        //Purpose: If empty, let's user know. Otherwise prints elements vertically
        void displayAll();

        //Checks if empty, if not, uses pop function repeatedly to remove all elements
        void clearIt();
  };
