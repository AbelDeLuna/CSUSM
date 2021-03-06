//HW1P2 vector stack
//Your name: Abel De Luna
//Complier:  g++
//File type: vector stack client.cpp
//================================================================

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
  stack postfixstack;
  string expression;
  cout << "type a postfix expression: " ;
  cin >> expression;

  int i = 0;  // character position within expression
  char item;

  int box1;  // to be used for receiving element upon pop request
  int box2;  // to be used for receiving element upon pop request
  int result; // result from operation stored here

  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i]; //read an item

	  if((item>='0') && (item<='9')) // checks if char is an int
	    {
	      result = (int (item)-48); // changes char into an in by subtracting value of 0 in ASCII
	      postfixstack.push(result);// pushes the result to the stack as an int
	    }

	  // else if it is an operator, pop the two operands
	  // and apply the operator to the two operands.
	  // Finally, push the result.

        else if ( (item == '+') || (item == '-') || (item == '*'))
        {
	      postfixstack.pop(box1); //pop current top operand into box1
	      postfixstack.pop(box2); //pop now current top operand into box2
          //if - Operator, add operands and push result
	        if (item == '-')
            {
                result = box2-box1;
                postfixstack.push(result);
            }
            //if + operator, subtract box2 from box1 and push result
            if (item == '+')
            {
                result = box2+box1;
                postfixstack.push(result);
            }
            //if *, multiply operands and push result
            if (item == '*')
            {
                result = box2*box1;
                postfixstack.push(result);
            }
	    }
    else throw "invalid item";
    } //end of try

      // Catch exceptions and report problems and quit the program
      catch (stack::Overflow)
	{
        //if stack is beyond full
	  cerr <<"Error: Too many elements" << endl;
	  exit(1);
	}
      catch (stack::Underflow)
	{
	  //if something is missing to complete the stack
	  cerr<< "Error: Missing operands."<<endl;
	  exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr<< "ERROR, Invalid Element" << endl;
	  exit(1);
	}
      // go back to the loop
      i++;

    }// end of while loop

  //  After the loop successfully completes:
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
  postfixstack.pop(result); //pop final result
  //exception handleing for case where stack contains 2 or more operands
  try
    {
      if (postfixstack.isEmpty() !=true)
        throw "Incomplete expression";
    }
  catch (char const* errorcode)
   {
     cerr<< "ERROR: "<< errorcode<< endl;
     exit(1);
   }

  cout << "The result is : " << result<< endl; //prints result

return 0;
}
