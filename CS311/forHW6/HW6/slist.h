#ifndef SLIST_H
#define SLIST_H

#include <vector>
#include "llist.h"

using namespace std;

// The searchable Linked List class
class slist: public llist
{
	public:
		// Public constructor/destructor.
		slist();			// Does not create any nodes, but init's front/rear to NULL
		~slist();			// Iteratively calls deleteFront() until the list is empty.

		// copy constructor
		slist(const slist& Original);

		// overloaded assignment operator
		slist& operator=(const slist& OtherOne);

		// overloaded equality-test operator
		bool operator==(const slist& OtherOne);

		// Member functions //
		int search(el_t Key);
		void replace(el_t Elem, int I);
};

#endif // SLIST_H
