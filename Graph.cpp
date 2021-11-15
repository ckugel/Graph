//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

#include <iostream>
#include <queue>
#include <stack>

template<typename V>
Graph<V>::Graph() {
    std::vector<unsigned int> temp;
    temp.push_back(0);
    temp.push_back(0);
    matrix.push_back(temp);
    matrix.push_back(temp);
}


template<typename V>
void Graph<V>::playGround() {
    Node<V> *tempNode = new Node<V>(0);
    addNode(tempNode);
    for (int creator = 1; creator <= 5; creator++) {
        addNode(new Node<V>(creator), tempNode);
    }

    head = nodes[1];

    for (int i = 1; i < nodes.size() - 1; i++) {
        if (nodes[i] != nodes[i + 1]) {
            addConnection(nodes[i], nodes[i + 1]);
        }
    }


    printOut();

    std::vector<Node<V>*> list = getAdj();

    std::cout << "Head: " << head->getData() << std::endl;

    std::cout << "Adjacent nodes: ";
    for (int looper = 0; looper < list.size(); looper++) {
        std::cout << list[looper]->getData();
        if (looper != list.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

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
void Graph<V>::addNode(Node<V>* newNode) {
    if (contains(newNode, nodes)) {return;}
    head = newNode;
    nodes.push_back(newNode);
    nodeMap[newNode] = nodes.size() - 1;
    resize();
}

template<typename V>
void Graph<V>::addNode(Node<V>* nextNode, std::vector<Node<V>*> adjacentNodes, unsigned int weight) {
    addNode(nextNode);
    for (int looper = 0; looper < adjacentNodes.size(); looper++) {
        if (!contains(adjacentNodes[looper], nodes)) {
            nodes.push_back(adjacentNodes[looper]);
            nodeMap[adjacentNodes[looper]] = nodes.size() - 1;
            resize();
        }
        resize();
        int currNodeNum = nodeMap.at(nextNode);
        int nextNodeNum = nodeMap.at(adjacentNodes[looper]);
        matrix[currNodeNum][nextNodeNum] = weight;
        matrix[nextNodeNum][currNodeNum] = weight;
    }
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
void Graph<V>::printOut() {
    for (int looper = 0; looper < nodes.size(); looper++) {
        std::cout << nodes[looper]->getData();
    }
    std::cout << std::endl;

    for (int anotherLoop = 0; anotherLoop < nodes.size(); anotherLoop++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int i = 0; i < matrix.size(); i++) {
        for (int ii = 0; ii < matrix[i].size(); ii++) {
            std::cout << matrix[i][ii];
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n\n" << std::endl;
}

template<typename V>
std::vector<Node<V>*> Graph<V>::getAdj() {
    std::vector<Node<V> *> adjacent;
    int index = nodeMap.at(head);

    for (int looper = 0; looper < matrix.size(); looper++) {
        if (matrix[index][looper] != 0) {
            adjacent.push_back(nodes[looper]);
        }
    }
    return adjacent;
}

template<typename V>
void Graph<V>::setHead(int index) {
    head = getAdj()[index];
}

template<typename V>
std::vector<Node<V>*> Graph<V>::Dijkstra(Node<V>* find) {
    std::vector<Node<V>*> path;
    if (head == find) {
        return path;
    }
    path.resize(nodes.size());
    bool visited[nodes.size()];
    unsigned int distances[nodes.size()];

    std::priority_queue<std::pair<int, Node<V>*>, std::vector<std::pair<int, Node<V>*>>, CustomCompare> queue;

    for(int filler = 0; filler < nodes.size(); filler++) {
        visited[filler] = 0;
        distances[filler] = INTMAX_MAX;

        if (nodes[filler] != find) {
            queue.push(nodes[filler]);
        }
    }
    while (!queue.empty()) {
        Node<V> *curr = queue.pop();
        for (int looper = 0; looper < getAdj().size(); looper++) {
            int tempDistance;
            if (visited[looper] == 0) {
                tempDistance = distances[nodeMap.at(curr)] + matrix[nodeMap.at(curr)][looper];
                if (tempDistance < distances[looper]) {
                    distances[looper] = tempDistance[nodeMap.at(curr)];
                    path[looper] = curr;
                }
            }
        }
    }
}

template<typename V>
void Graph<V>::addConnection(Node<V> *one, Node<V> *two, unsigned int weight) {
    int oneIndex = nodeMap.at(one);
    int twoIndex = nodeMap.at(two);

    matrix[oneIndex][twoIndex] = weight;
    matrix[twoIndex][oneIndex] = weight;

}

template<typename V>
void Graph<V>::addConnection(Node<V> *one, Node<V> *two) {
    addConnection(one, two, 1);
}

