
// CS311 : This is the BST implementation file template by Rika Yoshii

// ** Look for ** comments to complete this file for HW4
// Make sure all { } match.

// =========================================================

//HW4 BST
//Your name: Abel De Luna
//Complier:  g++
//File type: bintree source

//================================================================


#include <iostream>
using namespace std;

#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // post order traversal
{
  if (V != NULL)
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       // visit right sub tree of V
      delete V;                  // deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        INorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
        cout << V->Elem << endl; // ** display V's element and do endl;
        INorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
      }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        cout << V->Elem << endl;// ** display V's element and do endl;
        PREorderTraversal(V->Left);// ** traverse left sub-tree of V recursively
        PREorderTraversal(V->Right);// ** traverse right sub-tree of V recursively
      }
}


// PURPOSE: Adds a vertex to the binary search tree for new element
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
//     - smaller than the current -> go to the left
//     - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{

   Vertex *N;       // N will point to the new vertex to be inserted
   N = new Vertex;        // a new vertex is created
   N->Left  = NULL;     // make sure it does not
   N->Right = NULL;    // point to anything
   N->Elem  = E;            // put element E in it

   cout << "Trying to insert " << E << endl;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl;
     }

   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V

        while (V != NULL)  // go down the tree until you cannot go any further
        {
            if (N->Elem == V->Elem) // special case
            { 	 cout << "...error: the element already exists" << endl;
	     		 return;
            }
            else
            if (N->Elem < V->Elem)  // what I have is smaller than V
            {
                cout << "...going to the left" << endl;
                Parent = V; // ** change Parent to be V to go down
               	V = V->Left; // ** change V to be V's Left
            }
            else // what I have is bigger than V
            {
                cout << "...going to the right" << endl;
                Parent = V; // ** change Parent to be V to go down
                V = V->Right; // ** change V to be V's Right
            }

        }//end of while

        // reached NULL -- Must add N as the Parent's child

        if (N->Elem < Parent->Elem)
        {
            Parent->Left = N;// ** Parent's Left should point to the same place as N
            cout << "...adding " << E << " as the left child of "
                 << Parent->Elem << endl;
        }
        else
        {
            Parent->Right = N;// ** Parent's Right should point to the same place as N
            cout << "...adding " << E << " as the right child of "
                 << Parent->Elem << endl;
        }

      }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{

    cout << "Trying to delete " << E << endl;

    Vertex *V = Root;              // the current vertex
    Vertex *Parent = NULL;  // its parent

    if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    {
        cout << "...deleting the lonely root" << endl;
        delete Root;
        Root = NULL;
        return;
    }  // only the Root was there and deleted it

    if ((E == Root->Elem) && ((V->Left != NULL && V->Right == NULL) ||((V->Left == NULL && V->Right != NULL))))// ** if V is the root with one child
    {
        cout << "...deleting root with children" << endl;//{  ** change the root and return  }
        if (V->Left != NULL && V->Right != NULL)
        {
            Root->Elem = Root->Right->Elem;
            Remove(V->Right, Root);
        }
        else if (V->Left == NULL) //if lef is empty new root is child on right, delete root
        {
            Root = Root->Right;
            delete V;
        }
        else // if right is empty, new root is child on left, delete root
        {
            Root = Root->Left;
            delete V;
        }
        return;
    }
// Otherwise deleting something else

   while (V != NULL)
      {
         if ( E == V->Elem)   // found it
              {  cout << "...removing " << V->Elem << endl;
                 Remove(V, Parent);// ** call remove here to remove V
                 return; }

	    else
          if (E < V->Elem)
               {  cout << "...going to the left" << endl;
                  Parent = V;
                  V = V->Left; // ** update Parent and V here to go down
               }
               else
               {  cout << "...going to the right" << endl;
                  Parent = V;
                  V = V->Right;// ** update Parent and V here to go down
               }

       }// end of while

        // reached NULL  -- did not find it
        cout << "Did not find the key in the tree." << endl;

}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf � delete it
// Case 2: it has just one child � bypass it
// Case 3: it has two children � replace it with the max of the left //subtree

void BST::Remove(Vertex *V, Vertex *P)
{
    if (V->Left == NULL && V->Right == NULL)// ** if V is a leaf (case 1)
      {
        cout << ".. removing a leaf" << endl;
        if (P->Left == V)// ** if V is a left child of P
        {
            P->Left = NULL;// ** delete V and also make Parent's left NULL
            delete V;
        }
        else // V is a right child of the Parent
        {
            P->Right = NULL;// ** delete V and also make Parent's right NULL
            delete V;
        }
       }


    else if (V->Left != NULL && V->Right == NULL)// ** else if V has just the left child (case 2)
      {
         cout << "removing a vertex with just the left child" << endl;
         if (P->Left == V)// ** Make Parent�s left or right point to the left child and
         {
            P->Left = V->Left;
            delete V; //(You need if then else to determine left or right)
         }
         else
         {
             P->Right = V->Left;
             delete V;
         }
       }

    else if (V->Left == NULL && V->Right != NULL)// **else if V has just the right child
      {
       cout << "removing a vertex with just the right child" << endl;
       // ** Make Parent�s left or right point to the right child and delete V (need if then else to determine left or right)
         if (P->Right == V)// ** Make Parent�s left or right point to the left child and
         {
            P->Left = V->Right;
            delete V;
         }
         else
         {
             P->Right = V->Right;
             delete V;
         }
      }

   else // V has two children (case 3)
     {  cout << "...removing an internal vertex with children" << endl;
        cout << ".....find the MAX of its left sub-tree" << endl;
        elem_t Melem;
        Melem = findMax(V); // find MAX element in the left sub-tree of V
        cout << ".....replacing " << V->Elem << " with " << Melem << endl;
        V->Elem = Melem;// ** Replace V's element with Melem here
     }
 }// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{

     Vertex *Parent = V;
     V = V->Left;          // start with the left child of V

    while (V->Right != NULL)// ** while the right child of V is still available
          {
              Parent = V;// ** update Parent and V to go to the right
              V = V->Right;
          }

      // reached NULL Right  -- V now has the MAX element
        elem_t X = V->Elem;
        cout << ".....Max is " << X << endl;
        Remove(V, Parent);    // remove the MAX vertex
        return X;             // return the MAX element

}// end of FindMax

