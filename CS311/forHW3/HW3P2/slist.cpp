#include <iostream>
#include "slist.h"

slist::slist()
{
    Front = NULL;
    Rear = NULL;
    Count = 0;
}

int slist::search(el_t key)
{
    if (isEmpty())
    {
        throw Underflow(); //exception handling for list being empty
    }

    P = Front;
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
