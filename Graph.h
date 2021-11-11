//
// Created by caleb on 11/9/21.
//

#ifndef ANOTHERGRAPH_GRAPH_H
#define ANOTHERGRAPH_GRAPH_H

#include "vector"
#include "Node.cpp"
using namespace std;

template <typename V>
class Graph {
    protected:
        vector<Node<V>*> nodes;
        vector<vector<unsigned int>> matrix;
        Node<int>* head = nullptr;
        int findNode(Node<V>* node);
        void addNode(Node<V>* nextNode, Node<V>* nodeITSLATE);
        void addNode(Node<V>* nextNode, vector<Node<V>*> adjacentNodes);
        void addNode(Node<V>* nextNode, vector<Node<V>*> adjacentNodes, double weight);
        void resize();
    public:
        void playGround();
        void printOut();
};


#endif //ANOTHERGRAPH_GRAPH_H
