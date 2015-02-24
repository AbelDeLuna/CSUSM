 /*
Author: Abel De Luna
FileName: Main.cpp for HW6
Compiler: G++
*/

#include <iostream>
#include <ctype.h>

#include "dgraph.h"


void AdjList(dgraph& myGraph);
void Degree(dgraph& myGraph);

int main()
{
	dgraph myGraph = dgraph();

	cout << "Opening table.txt" << endl;
	myGraph.fillTable(); // pulls vertex data from table.txt

	int input;
	while (input != 4)
	{
		// Menu that prompts the user for input and loops until 4 is chosen
		cout << "What would you like to do?:" << endl
            << "1. Find Adjacency List of a vertex" << endl
            << "2. Find Degree of a vertex" << endl
            << "3. Display the graph" << endl
            << "4. Quit" << endl
            << "Enter either 1,2,3,or 4: ";
		cin >> input;

		switch (input)
		{
        case 1:
            AdjList(myGraph);
            break;
        case 2:
            Degree(myGraph);
            break;
        case 3:
            cout << "Vertex\tDegree\tAdjacencyList" << endl;
			myGraph.displayGraph();
			break;
        case 4:
            input = 4;
            break;
        default:
            cout << "Invalid input, try again." << endl;
            break;
		}
	}
	return(0);
}

void AdjList(dgraph& myGraph)
{
	slist adj_list = slist();
    string input;
	cout << "What vertex would you like to search for?: " ;
	cin >> input;

	char vertex = toupper(input[0]);

	cout << "Searching for vertex " << vertex << endl;
	try
	{
		adj_list = myGraph.findAdjacencyList(vertex);
		cout << "The adjacency list for that vertex is:" << endl;
		adj_list.displayAll();
	}
	catch (dgraph::VertexNotFound)
	{
		cout << "Couldn't find that vertex in the graph." << endl;
	}
}

void Degree(dgraph& myGraph)
{
    string input;
	cout << "What vertex would you like to search for?: ";
	cin >> input;

	char vertex = toupper(input[0]);

	cout << "Searching for vertex " << vertex << endl;
	try
	{
		cout << "The out degree for that vertex is: " << endl;
        myGraph.findOutDegree(vertex);
	}
	catch (dgraph::VertexNotFound)
	{
		cout << "Couldn't find the vertex in the graph." << endl;
	}
}
