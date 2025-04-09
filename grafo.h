#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "list.h"
#include "structs.h"
using namespace std;

template <typename T>
class Graph {
private:
    List<Vertex<T>> vertices;
    Node<Vertex<T>>* findVertexNode(const T &data);
public:
    Graph();
    void addVertex(const T &data);
    void addEdge(const T &src, const T &dest, bool directed = false);
    void removeEdge(const T &src, const T &dest, bool directed = false);
    void removeVertex(const T &data);
    void print();
};

#endif