#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dgraph.h"

using namespace std;

dgraph::dgraph()
{
    count = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Gtable[i].name = '\0';
        Gtable[i].mark = 0;
        Gtable[i].outDegree = 0;
    }
}

dgraph::~dgraph()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (Gtable[i].name != '\0')
        {
            Gtable[i].adjList.~slist();
        }
    }
}

void dgraph::fillTable()
{
    // Opens the file
    ifstream file("table.txt");
    string line;
    int i = 0; // Counter to loop through the Gtable array.
    // Loops over the file one line at a time.
    while(getline(file, line))
    {
        char vertName;
        int outDegree;
        char adjVertex;
        slist adjList = slist();
        // this lets us easily output whitespace delimited 'formatted' text into variables.
        stringstream listream(line);
        listream >> vertName;
        listream >> outDegree;
        // everything left in listream (if anything!) is an adjacent vertex
        while(listream >> adjVertex)
        {
            adjList.addRear(adjVertex);
        }
        // Now that we have successfully pulled data from the line, populate a Gvertex with it.
        Gvertex vert;
        vert.name = vertName;
        vert.mark = 0;
        vert.outDegree = outDegree;
        vert.adjList = adjList; // Calls copy constructor of slist.
        Gtable[i] = vert;
        i++;
        count++;
    }
    // When the loop ends, we've read every line of the file.
    // file (an ifstream object) closes automatically at the end of fillTable()
}
// Displays the graph in a neat tabular format.
// Simply loops over Gtable, MAX_SIZE times.
// Checks to see if name is != the nul character. If so, vertex is empty, and don't print.
// Otherwise, print the vertex name, out degree, and adjacency list
void dgraph::displayGraph()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (Gtable[i].name != '\0')
        {
            cout << Gtable[i].name << '\t';
            cout << Gtable[i].mark << '\t';
            cout << Gtable[i].outDegree << '\t';
            Gtable[i].adjList.displayAll(); // Note, calls slist's displayAll()
        }
    }
}
// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, return the out_degree as an integer.
// Otherwise throws VertexNotFound if that vertex doesn't exist.
int dgraph::findOutDegree(char vertexName)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (vertexName == Gtable[i].name)
        {
            return(Gtable[i].outDegree);
        }
    }
    throw(dgraph::VertexNotFound());
}
// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, return true if the vertex's mark is > 0.
// Otherwise, return false.
// Otherwise, if not found throws VertexNotFound.
bool dgraph::isMarked(char vertexName)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (vertexName == Gtable[i].name)
        {
            if (Gtable[i].mark > 0)
            {
                return(true);
            }
            else
            {
                return(false);
            }
        }
    }
    throw(dgraph::VertexNotFound());
}
// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, set the vertex's mark to the given int
// Otherwise, if not found throws VertexNotFound.
void dgraph::visit(int markOrder, char vertexName)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (vertexName == Gtable[i].name)
        {
            Gtable[i].mark = markOrder;
            return;
        }
    }
    throw(dgraph::VertexNotFound());
}
// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, return a copy of the adjacency list
// Otherwise throws VertexNotFound if that vertex doesn't exist.
slist dgraph::findAdjacencyList(char vertexName)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (vertexName == Gtable[i].name)
        {
            return(Gtable[i].adjList); // Implicitly calls copy constructor of slist
        }
    }
    throw(dgraph::VertexNotFound());
}
