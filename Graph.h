//
// Created by caleb on 11/9/21.
//

#ifndef ANOTHERGRAPH_GRAPH_H
#define ANOTHERGRAPH_GRAPH_H

#include "Node.cpp"

#include "vector"
#include "map"

template <typename V>
class Graph {
    protected:
        bool first = false;
        std::vector<Node<V>*> nodes;
        std::vector<std::vector<unsigned int>> matrix;
        Node<int>* head = nullptr;
        std::map<Node<V>*, unsigned int> nodeMap;

        void addNode(Node<V>* nextNode, Node<V>* nodeITSLATE);
        void addNode(Node<V>* nextNode, std::vector<Node<V>*> adjacentNodes);
        void addNode(Node<V>* nextNode, std::vector<Node<V>*> adjacentNodes, unsigned int weight);
        void resize();

        bool contains(Node<V>* node, std::vector<Node<V>*> listOfNodes);

        void search();

    public:
        void playGround();
        void printOut();

        void findShortestPath();

        void setHead(int index);

        std::vector<Node<V>*> getAdj();

        Graph();
};


#endif //ANOTHERGRAPH_GRAPH_H
