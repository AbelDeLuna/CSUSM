/*
Author: Abel De Luna
File type: dgraph.h
Compiler: g++
*/

#ifndef DGRAPH_H
#define DGRAPH_H

#include "slist.h"

using namespace std;
const int MAX_SIZE = 20;

class dgraph
{
    public:
        dgraph();
        virtual ~dgraph();
        class VertexNotFound {};

		// Member functions
		void fillTable();
		void displayGraph();
		int findOutDegree(char vertex_name);
		slist findAdjacencyList(char vertex_name);
    protected:

		struct Gvertex
		{
			char name;
			int mark;
			int out_degree;
			slist adj_list;
		};
		Gvertex Gtable[MAX_SIZE];
		int count;
    private:
};

#endif // DGRAPH_H
