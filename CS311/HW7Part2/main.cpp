#include <iostream>
#include <ctype.h>
#include "stack.h"
#include "dgraph.h"

using namespace std;

int main()
{
    dgraph myGraph = dgraph();
    stack myStack = stack();

    cout << "Opening table.txt" << endl;
    myGraph.fillTable();


    cout << "Graph data:" << endl;
    myGraph.displayGraph();
    slist vertexAdjList = slist();

    char vertex = 'A';
    cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
    vertexAdjList = myGraph.findAdjacencyList(vertex);

    int count = 1; //this count will be used for tracking order of tree
    myGraph.visit(count, vertex);

    // Add the contents of this vertex's adjacency list to our stack
    while (!vertexAdjList.isEmpty())
    {
        vertexAdjList.deleteRear(vertex);
        myStack.push(vertex);
    }
    myStack.displayAll();
    while (!myStack.isEmpty())
    {

        myStack.pop(vertex);
        cout << "Visiting vertex '" << vertex << "'" << endl;
        if (!myGraph.isMarked(vertex))
        {
            cout << "Vertex '" << vertex << "' has not been visited." << endl;
            cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
            count++;
            myGraph.visit(count, vertex); //fills this vertex's order field
            vertexAdjList = myGraph.findAdjacencyList(vertex);
            char adjVertex;

            while (!vertexAdjList.isEmpty())
            {
                vertexAdjList.deleteRear(adjVertex);
                myStack.push(adjVertex);
            }
            cout << "Stack contents after adding the adjacency list of vertex '" << vertex << "':" << endl;
            myStack.displayAll();
        }
        else
        {
            cout << "Vertex '" << vertex << "' has already been visited." << endl;
        }
    }
    cout << "Graph data, visited:" << endl;
    myGraph.displayGraph();
    return(0);
}
