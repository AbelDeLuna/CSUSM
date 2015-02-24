#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "dgraph.h"

void dgraph::fillTable()
{
    int i = 0; // Counter to loop through the Gtable array.
	ifstream file("table.txt"); // Opens the file
	string line;

	// Loops over the file, one line at a time.
	while(getline(file, line))
	{
		char vert_name;
		int out_degree;
		char adj_vertex;

		slist adj_list = slist();

		//outputs whitespace
		stringstream listream(line);

		listream >> vert_name;
		listream >> out_degree;
		// everything left in listream is an adjacent vertex
		//loopa until everything in the file has been read
		while(listream >> adj_vertex)
		{
			adj_list.addRear(adj_vertex);
		}

		Gvertex vert;
		vert.name = vert_name;
		vert.out_degree = out_degree;
		vert.adj_list = adj_list; // Calls copy constructor of slist.

		Gtable[i] = vert;
		i++;
		count++;
	}
}

void dgraph::displayGraph()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Gtable[i].name != '\0')
		{
			cout << Gtable[i].name << '\t';
			cout << Gtable[i].out_degree << '\t';
			Gtable[i].adj_list.displayAll();  // Note, calls slist's displayAll()
		}
	}
}

int dgraph::findOutDegree(char vertex_name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (vertex_name == Gtable[i].name)
		{
			return(Gtable[i].out_degree);
		}
	}
	throw(dgraph::VertexNotFound());
}

slist dgraph::findAdjacencyList(char vertex_name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (vertex_name == Gtable[i].name)
		{
			return(Gtable[i].adj_list); // Implicitly calls copy constructor of slist
		}
	}
	throw(dgraph::VertexNotFound());
}

dgraph::dgraph()
{
	count = 0;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		Gtable[i].name = '\0';
		Gtable[i].mark = 0;
		Gtable[i].out_degree = 0;
	}
}

dgraph::~dgraph()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Gtable[i].name != '\0')
		{
			// the slist destructor, iteratively destroys every item in the list
			Gtable[i].adj_list.~slist();
		}
	}
}
