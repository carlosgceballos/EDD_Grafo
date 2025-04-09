#include <iostream>
#include "list.h"
using namespace std;

template <typename T>
struct Edge {
  T dest;
  Edge(T d):dest(d){
  }
  bool operator<(const Edge<T>& other) const {
       return dest < other.dest;
   }
  bool operator==(const Edge<T>& other) const {
       return dest == other.dest;
   }
};

template <typename T>
struct Vertex {
  T data;
  List<Edge<T>> edges;
  Vertex(T d):data(d), edges(nullptr){
  }
  bool operator<(const Vertex<T>& other) const {
       return data < other.data;
    }
  bool operator==(const Vertex<T>& other) const {
       return data == other.data;
    }
};