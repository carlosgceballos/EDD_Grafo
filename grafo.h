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
    void modifyVertex(const T &oldData, const T &newData);
};

// Definición del constructor
template <typename T>
Graph<T>::Graph() : vertices(nullptr) { }

template <typename T>
Node<Vertex<T>>* Graph<T>::findVertexNode(const T &data) {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        if (current->getData().data == data) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

template <typename T>
void Graph<T>::addVertex(const T &data) {
    if (!findVertexNode(data))
        vertices.insert(Vertex<T>(data));
}

template <typename T>
void Graph<T>::addEdge(const T &src, const T &dest, bool directed) {
// Asegurarse de que ambos vértices existan
    addVertex(src);
    addVertex(dest);
    Node<Vertex<T>>* srcNode = findVertexNode(src);
    if (srcNode) {
        srcNode->getData().edges.insert(Edge<T>(dest));
    }
    if (!directed) {
        Node<Vertex<T>>* destNode = findVertexNode(dest);
        if (destNode) {
            destNode->getData().edges.insert(Edge<T>(src));
        }
    }
}

template <typename T>
void Graph<T>::removeEdge(const T &src, const T &dest, bool directed) {
    Node<Vertex<T>>* srcNode = findVertexNode(src);
    if (srcNode) {
        srcNode->getData().edges.remove(Edge<T>(dest));
    }
    if (!directed) {
        Node<Vertex<T>>* destNode = findVertexNode(dest);
        if (destNode) {
            destNode->getData().edges.remove(Edge<T>(src));
        }
    }
}

template <typename T>
void Graph<T>::removeVertex(const T &data) {
    vertices.remove(Vertex<T>(data));
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        current->getData().edges.remove(Edge<T>(data));
        current = current->getNext();
    }
}

template<class T>
void Graph<T>::modifyVertex(const T &oldData, const T &newData) {
    // Buscar el vértice que se quiere modificar
    Node<Vertex<T>>* vNode = findVertexNode(oldData);
    if (!vNode) {
         cout << "El vertice '" << oldData << "' no existe." << endl;
         return;
    }
    
    // Actualizar el dato del vértice
    vNode->getData().data = newData;
    
    // Recorrer todos los vértices para actualizar las aristas que tienen
    // como destino el antiguo valor oldData
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
         Node<Edge<T>>* edgeNode = current->getData().edges.getHead();
         while (edgeNode != nullptr) {
              if (edgeNode->getData().dest == oldData) {
                  // Se actualiza la referencia en la arista al nuevo valor
                  edgeNode->getData().dest = newData;
              }
              edgeNode = edgeNode->getNext();
         }
         current = current->getNext();
    }
}

template<class T>
void Graph<T>::print() {
    cout << "\n---- Informacion del Grafo ----" << endl;
    Node<Vertex<T>>* current = vertices.getHead();
    while (current != nullptr) {
        Vertex<T>& vert = current->getData();
        
        cout << "Vertice: " << vert.data << endl;
        cout << "  Conexiones: ";
        
        Node<Edge<T>>* edgeNode = vert.edges.getHead();
        if (edgeNode == nullptr) {
            cout << "Ninguna";
        }
        else {
            while (edgeNode != nullptr) {
                cout << edgeNode->getData().dest;
                if (edgeNode->getNext() != nullptr) {
                    cout << ", ";
                }
                edgeNode = edgeNode->getNext();
            }
        }
        cout << endl << "--------------------------------" << endl;
        current = current->getNext();
    }
}

#endif