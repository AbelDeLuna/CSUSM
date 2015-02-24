// ========================================================
//HW2P1 Binary Search main program
//Your name: Abel De Luna
//Complier:  g++
//File type: Binary Search main
//==========================================================
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//introducing the function that will be used
int binarySearch(int A[], int lookfor, int myfirst,int  mylast);

int main()
{
  int A[]= {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = sizeof(A)/sizeof(A[0]); // n==#of elements in the array
  int  myfirst =0; // initiates starting position as 0
  int mylast = n - 1;// tracks previous possition
  int lookfor;// user entered search target

  cout << "Enter the # you would like to search for:  ";
  cin >>lookfor;

  //Calls for the Binary Search function and look for the number entered.
  int  location = binarySearch(A, lookfor, myfirst, mylast);

    // if found, this will print out the location
    if (location >= 0)
        cout << "The # "<< lookfor<< " is in position "<< location+1<< ".";
    // If not found, display error screen
    else
    {
        cout << "The # "<< lookfor << " was not found.";
    }
  return 0;
}
// End of Main

int binarySearch(int A[], int lookfor, int myfirst,int  mylast)
{
    if (myfirst>mylast)// stopping case
        return -1; // ends program if not found

    int middle =(myfirst+mylast)/2;// divides the array in half

    if(lookfor == A[middle])// checks if middle is the number that we are looking for.
	  return middle;// if so, returns the number

    //of tje numer we are searching for is less than the middle, search in the first half
    else if (lookfor < A[middle])
    //of tje numer we are searching for is less than the middle, search in the first half
      {
        mylast = middle - 1;// go to the first half
        return binarySearch( A,lookfor, myfirst, mylast);
      }
    //of the number we search for is greater than the middle, search the second half
    else if (lookfor > A[middle])
	{
	  myfirst = middle + 1;// go to second half
	  return binarySearch( A,lookfor, myfirst, mylast);
    }
    else
    {
        return -1;
    }
}







