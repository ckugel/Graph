//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

#include <iostream>

template<typename V>
void Graph<V>::playGround() {
  Node<int> tempNode(5);
  head = tempNode;
  
}

template<typename V>
int Graph<V>::findNode(Node<V>* node) {
  for (int nodeFinder = 0; nodeFinder < nodes.size(); nodeFinder++) {
    if (nodes[nodefinder] == tempNode) {
      return nodeFinder;
    }
  }
}

template<typename V>
void Graph<V>::resize() {
  vector<int> random;
  matrix.push_back(random);
  for (int matLooper = 0; matLooper < matrix.size(); matLooper++) {
    matrix[matLooper].push_back(0);
  }
}

template<typename V>
void Graph<V>::matrixShananigans(Node<V>* nextNode, vector<Node<V>*> adjacentNodes, unsigned int weight) {
  head = nextNode;
  nodes.push_back(node);
  resize();
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
