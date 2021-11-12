//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

#include <iostream>

template<typename V>
void Graph<V>::playGround() {
    Node<V> *tempNode = new Node<V>(5);
    std::vector<Node<V>*> adj;
    head = tempNode;
    for (int creator = 0; creator < 5; creator++) {
        Node<V> *nextNode = new Node<V>(5);
        addNode(nextNode, tempNode);
    }
    addNode(tempNode, adj);
    printOut();
}

template<typename V>
void Graph<V>::resize() {
    matrix.resize(nodes.size());
    for (std::vector<unsigned int>& looper : matrix) {
        looper.resize(nodes.size());
    }
}

template<typename V>
bool Graph<V>::contains(Node<V>* node, std::vector<Node<V>*> listOfNodes) {
    for (int looper = 0; looper < listOfNodes.size(); looper++) {
        if (node == listOfNodes[looper]) {
            return true;
        }
    }
    return false;
}

template<typename V>
void Graph<V>::addNode(Node<V>* nextNode, std::vector<Node<V>*> adjacentNodes, unsigned int weight) {
    if (contains(nextNode, nodes)) {return;}
    head = nextNode;
    nodes.push_back(nextNode);
    nodeMap[nextNode] = nodes.size() - 1;
    printOut();
    for (int looper = 0; looper < adjacentNodes.size(); looper++) {
        if (!contains(adjacentNodes[looper], nodes)) {
            nodes.push_back(adjacentNodes[looper]);
            nodeMap[adjacentNodes[looper]] = nodes.size() - 1;
            resize();
        }
        resize();
        printOut();
        int currNodeNum = nodeMap.at(nextNode);
        int nextNodeNum = nodeMap.at(adjacentNodes[looper]);
        matrix[currNodeNum][nextNodeNum] = weight;
        matrix[nextNodeNum][currNodeNum] = weight;
    }
}

template<typename V>
void Graph<V>::printOut() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int ii = 0; ii < matrix[i].size(); ii++) {
            std::cout << matrix[i][ii];
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n\n\n\n" << std::endl;
}

template<typename V>
void Graph<V>::addNode(Node<V> *nextNode, std::vector<Node<V>*> adjacentNodes) {
    addNode(nextNode, adjacentNodes, 1);
}

template<typename V>
void Graph<V>::addNode(Node<V> *nextNode, Node<V> *nodeITSLATE) {
    std::vector<Node<V>*> adj;
    adj.push_back(nodeITSLATE);
    addNode(nextNode, adj);
}


template<typename V>
Graph<V>::Graph() {
    std::vector<unsigned int> temp;
    temp.push_back(0);
    temp.push_back(0);
    matrix.push_back(temp);
    matrix.push_back(temp);
}