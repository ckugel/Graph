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
        vector<vector<int>> matrix;
        Node<V>* head;
        int findNode(Node<V>* node) {
            for (int nodeFinder = 0; nodeFinder < nodes.size(); nodeFinder++) {
              if (nodes[nodefinder] == tempNode) {
                return nodeFinder;
              }
            }
        }
        void matrixShananigans(Node<V>* nextNode, vector<Node<V>*> adjacentNodes) {
          head = nextNode;
          nodes.push_back(node);
          for (int looper = 0; looper < adjacentNodes.size(); looper++) {
            int nodeNum = findNode(adjacentNodes[looper]);
          }
        };
    public:
        void playGround();
};


#endif //ANOTHERGRAPH_GRAPH_H
