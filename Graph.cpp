//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

#include <iostream>

template<typename V>
void Graph<V>::playGround() {
    Node<V> *tempNode = new Node<V>(5);
    vector<Node<V>*> adj;
    head = tempNode;
    for (int creator = 0; creator < 5; creator++) {
        Node<V> *nextNode = new Node<V>(5);
        addNode(nextNode, tempNode);
    }
    addNode(tempNode, adj);
    printOut();
}

template<typename V>
int Graph<V>::findNode(Node<V>* node) {
    for (int nodeFinder = 0; nodeFinder < nodes.size(); nodeFinder++) {
        if (nodes[nodeFinder] == node) {
            return nodeFinder;
        }
    }
    return 0;
}

template<typename V>
void Graph<V>::resize() {
    vector<unsigned int> random;
    matrix.push_back(random);
    for (int matLooper = 0; matLooper < matrix.size(); matLooper++) {
        matrix[matLooper].push_back(0);
    }
}

template<typename V>
void Graph<V>::addNode(Node<V>* nextNode, vector<Node<V>*> adjacentNodes, double weight) {
    resize();
    head = nextNode;
    nodes.push_back(nextNode);
    for (int looper = 0; looper < adjacentNodes.size(); looper++) {
        int currNodeNum = findNode(nextNode);
        int nextNodeNum = findNode(adjacentNodes[looper]);
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
}

template<typename V>
void Graph<V>::addNode(Node<V> *nextNode, vector<Node<V> *> adjacentNodes) {
    addNode(nextNode, adjacentNodes, 1);
}

template<typename V>
void Graph<V>::addNode(Node<V> *nextNode, Node<V> *nodeITSLATE) {
    vector<Node<V>*> adj;
    adj.push_back(nodeITSLATE);
    addNode(nextNode, adj);
}
