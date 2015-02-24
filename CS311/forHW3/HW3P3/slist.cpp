#include <iostream>
#include "slist.h"

slist::slist()
{
    Front = NULL;
    Rear = NULL;
    Count = 0;
}


// Overloaded assignment operator.
// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference
slist& slist::operator=(const slist& OtherOne)
{
// First make sure this-> and OtherOne are not the same object.
// To do this, compare the pointers to the objects.
    if (&OtherOne != this)
    {
// In case we are copying into a list with existing entries,
// this-> object has to be emptied first.
        el_t elem;
        while (!this->isEmpty())	// Loops through, deleting until empty
        {
            this->deleteRear(elem);
        }
// temp is a pointer we use to copy elements from OtherOne, starting at the beginning
        P= OtherOne.Front;
// Note, we add to rear from the front of the OtherOne to preserve order.
        while (P != NULL)	// Loops until you reach the end of OtherOne.
        {
            this->addRear(P->Elem);	//P element is added to this->
            P = P->Next;
        }
    }
    return *this;	// Return this, whether it is the same object or a different one
}
// This is a copy constructor.
// This creates a copy of the Original list, item for item.
// Note that the Original is being passed to the constructor by reference
slist::slist(const slist& Original)
{
// Initializing the private members of the new list
    Front = NULL;
    Rear = NULL;
    Count = 0;
// P is used as a  pointer to copy elements from Original
    P = Original.Front;
// Note, we add to rear from the front of the OtherOne to preserve order.
    while (P != NULL)	// Loops until you reach the end of Original.
    {
        this->addRear(P->Elem);	//P element is added to this->
        P = P->Next;
    }
// Nothing to return, we've filled this object by reference
}
/* --I couldn't get this to work properly --
// Overloaded equality-test operator.
// This operator is used to see if two list objects contain the same content.
// We test 3 special cases before testing the elements in the lists objects.
// Case 1) if both lists are empty,
// Case 2) if they are the same object (they share the same memory location).
// Lists are definitely not identical if: (return(false);)
// Case 3) if the lists are different sizes.
// After these test cases are checked,
// you must then iterate through both lists, comparing each item
// As soon as you find a difference, you (return(false);)
bool slist::operator==(const slist& OtherOne)
{
// Case 1
// if they are both empty, they're the same (contents identical)
// Note that the case where one is empty but the other is not is covered by case 3
    if (OtherOne.isEmpty() && this->isEmpty())
    {
        return true;
    }
// Case 2
// If they point the same location in memory, they must be the same object.
// If they're the same object they must be equal.
    if (&OtherOne == this)
    {
        return true;
    }
// Case 3
// if they are of different sizes, they must be different
    if (Count != OtherOne.Count)
    {
    return false;
    }
// Case 4
// if the last 3 cases passed, we'll start checking if the two are the same
    Node* P_this = Front;
    Node* P_other = OtherOne.Front;
    while (P_this != NULL)	// Loop until the end of the list (or we find a difference)
    {
        if (P_this->Elem != P_other->Elem)	// Check for equality of elements
        {
            return false;
        }
        P_this = P_this->Next;
        P_other = P_other->Next;
    }
    return true; //returns true if at no time in the while loop did we return false
}
*/
int slist::search(el_t key)
{
    if (isEmpty())
    {
        throw Underflow(); //exception handling for list being empty
    }

    P = Front;
    //int i = 0;
    int position = 1;
    while (P != NULL) //keep running this until either we find the key or hit the end
    {
        if (P->Elem == key) //if found, return the position
            {
                cout << key << " was found in position " << position << endl;
                return position;
            }

        else
            P = P->Next;
            position++;
    }
    cout << key << " is not in the list." << endl;
    //throw OutOfRange;
    return 0;

}

void slist::replace(el_t Elem, int I)
{
    cout << "count: " << Count << endl;
    if (isEmpty())
    {
        throw Underflow(); //exception handling for list being empty
    }
    if (I > Count+1 || I ==0)
    {
        throw OutOfRange(); //exception handling for position being greater than count
    }
    else
    {
        P = Front;
        for (int i=1; i<I; i++) //run through the list I amount of times
        {
            P= P->Next;
        }
        P->Elem = Elem; //switch that positions elem to the new one
    }


}
