//
// Created by caleb on 11/9/21.
//

#ifndef ANOTHERGRAPH_GRAPH_H
#define ANOTHERGRAPH_GRAPH_H

#include "vector"
#include "Node.h"
using namespace std;

template <typename V>
class Graph {
    private:
        vector<Node<V>*> nodes;
        vector<vector<unsigned int>> matrix;
        Node<V>* head;
        int findNode(Node<V>* node);
        void matrixShananigans(Node<V>* nextNode, vector<Node<V>*> adjacentNodes);
        void resize();
    public:
        void playGround();
        void print();
};


#endif //ANOTHERGRAPH_GRAPH_H
