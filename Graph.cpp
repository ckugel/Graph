//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

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
void Graph<V>::matrixShananigans(Node<V>* nextNode, vector<Node<V>*> adjacentNodes) {
  head = nextNode;
  nodes.push_back(node);
  for (int looper = 0; looper < adjacentNodes.size(); looper++) {
    int currNodeNum = findNode(nextNode);
    int nextNodeNum = findNode(adjacentNodes[looper]);
    matrix[currNodeNum][nextNodeNum] = 1;
    std::swap(currNodeNum, nextNodeNum);
    matrix[currNodeNum][nextNodeNum] = 1;
    std::swap(currNodeNum, nextNodeNum);
  }
}
