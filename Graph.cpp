//
// Created by caleb on 11/9/21.
//

#include "Graph.h"

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "limits.h"

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
    Node<V> *tempNode = new Node<V>(1);
    addNode(tempNode);
    // srand(time(0));

    addNode(new Node<V>(2), tempNode, 2);
    addNode(new Node<V>(3), nodes[1], 1);
    addConnection(nodes[2], tempNode, 4);
    addNode(new Node<V>(4), nodes[2], 3);

    head = nodes[0];


    printOut();

    printAdjacent(head);

    std::cout << std::endl;

    std::vector<Node<V>*> path = Dijkstra(nodes[nodes.size() - 1]);

    std::cout << "goal: " << nodes.size() - 1 << std::endl;

    std::cout << "\n\n\n Path: ";
    if (!path.empty()) {
        for (int looper = 0; looper < path.size(); looper++) {
            if (looper != path.size() - 1) {
                std::cout << nodeMap.at(path[looper]) << "->";
            } else {
                std::cout << nodeMap.at(path[looper]);
            }
        }
        std::cout << std::endl;
    }

/*    std::cout << "\n\n\n Vals: " << std::endl;
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << i << " -> " << nodes[i] << std::endl;
    }*/


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
std::vector<Node<V>*> Graph<V>::getAdj(Node<V>* next) {
    std::vector<Node<V> *> adjacent;
    int index = nodeMap.at(next);

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
    std::vector<Node<V>*> thing;
    if (head == find) {
        return thing;
    }
    std::vector<bool> visited;
    visited.resize(nodes.size());
    unsigned int distances[nodes.size()];

    for(int filler = 0; filler < nodes.size(); filler++) {
        visited[filler] = 0;
        distances[filler] = UINT_MAX;
    }
    distances[0] = 0;

    std::priority_queue<pair, std::vector<pair>, CustomCompare> queue;
    std::vector<Node<V>*> temp;
    temp.push_back(head);
    queue.push(std::pair<unsigned int, std::vector<Node<V>*>>(0, temp));

    while (!queue.empty()) {
        std::vector<Node<V>*> path = queue.top().second;        
        Node<V> *curr = path[path.size() - 1];
        unsigned int currentDistance = queue.top().first;
        queue.pop();

        visited[nodeMap.at(curr)] = 1;

        if (find == curr) {
            std::cout << "\n\nDistance: " << currentDistance << std::endl;
            return path;
        }

        std::vector<Node<V>*> adj = getAdj(curr);

        for (int looper = 0; looper < adj.size(); looper++) {
            printAdjacent(curr);
            if (!visited[nodeMap.at(adj[looper])] && currentDistance + matrix[nodeMap.at(curr)][nodeMap.at(adj[looper])] < distances[nodeMap.at(adj[looper])]) {
                distances[nodeMap.at(adj[looper])] = currentDistance + matrix[nodeMap.at(curr)][nodeMap.at(adj[looper])];
                if (numVisited(visited) >= path.size() - 1) {
                    path.push_back(adj[looper]);
                }
                else {
                    path[numVisited(visited)] = adj[looper];
                }
                queue.push(std::pair<unsigned int, std::vector<Node<V>*>>(currentDistance + matrix[nodeMap.at(curr)][nodeMap.at(adj[looper])], path));
            }
        }
        thing = path;
    }
    return thing;
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

template<typename V>
void Graph<V>::addNode(Node<V> *nextNode, Node<V> *nodeITSLATE, unsigned int weight) {
    std::vector<Node<V>*> adj;
    adj.push_back(nodeITSLATE);
    addNode(nextNode, adj, weight);
}

template<typename V>
int Graph<V>::numVisited(std::vector<bool> listOfBools) {
    int counter = 0;
    for (int i = 0; i < listOfBools.size(); i++) {
        if (listOfBools[i]) {
            counter++;
        }
    }
    return counter;
}

template<typename V>
void Graph<V>::printAdjacent(Node<V>* next) {
    std::vector<Node<V>*> list = getAdj(next);
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
