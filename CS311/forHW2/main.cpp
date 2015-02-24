//HW2P2 Merge sort program
//Your name: Abel De Luna
//Complier:  g++
//File type: merge sort main
//==========================================================
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Combine(vector<int>& A, vector<int>& B, vector<int>& R);
void printVector (const vector<int>& L);

int main()
{
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    int input;

    cout << "Enter 13 integers in accending order to be placed into L1" << endl;
    cin >> input;
    L1.push_back(input);
    cin >> input;
    L1.push_back(input);
    cin >> input;
    L1.push_back(input);

    printVector(L1);

    cout <<"Enter 3 integers in accending order to be placed into L2" << endl;
    cin >> input;
    L2.push_back(input);
    cin >> input;
    L2.push_back(input);
    cin >> input;
    L2.push_back(input);

    printVector(L2);

    Combine (L1, L2, L3);
    printVector(L3);
    return 0;
}

void Combine(vector<int>& A, vector<int>& B, vector<int>& R)  // combine sorted lists A and B
{
    int ia = 0; // index for A
    int ib = 0; // index for B
    int ir = 0; // index for R

    while ((ia != 3) || (ib != 3))
    {
        //if (ia < ib)
        if (A[ia] < B[ib])
        {
        R[ir] = A[ia];
        //R.push_back(A[ia]);
        //A.erase(A.front());
        ia = ia + 1; // get the A element
        }
        else
        {
        R[ir] = B[ib];
            //R.push_back(B.front());
            //B.erase(B.front());
        ib = ib + 1; // get the B element
        }
    ir = ir +1;
        //printVector(R);
    }
    //After the loop:
    //if you still have A elements left, copy them into R
    if (ia == 3)
    {
        for (unsigned i = ib; i < 3; i++)
        {
            //R.push_back(B.front());
            //B.erase(B.begin());
            R[ir] = A[ib];
        }
    }
    //else copy the remaining B elements into R.
    else
    {
        for (unsigned i = ia; i < 3; i++)
        {
            //R.push_back(A.front());
            //A.erase(A.begin());
            R[ir] = A[ia];
        }
    }
    //ir = ir + 1;
}

void printVector (const vector<int>& L)
{
    for (unsigned int i= 0; i<L.size(); i++)
    cout << L[i] << " ";
}
