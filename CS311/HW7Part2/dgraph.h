#ifndef DGRAPH_H
#define DGRAPH_H

#include "slist.h"

using namespace std;
const int MAX_SIZE = 20;

class dgraph
{
    protected:
        struct Gvertex
        {
            char name;
            int mark;
            int outDegree;
            slist adjList;
        };
        Gvertex Gtable[MAX_SIZE];
        int count;
    public:
        dgraph();
        ~dgraph();
        class VertexNotFound {};
        void fillTable();
        void displayGraph();
        int findOutDegree(char vertexName);
        slist findAdjacencyList(char vertexName);
        bool isMarked(char vertexName);
        void visit(int markOrder, char vertexName);
    };

#endif // DGRAPH_H
