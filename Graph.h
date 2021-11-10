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
    public:
        void playGround();
};


#endif //ANOTHERGRAPH_GRAPH_H
