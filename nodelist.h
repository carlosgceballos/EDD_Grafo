#ifndef NODELIST_H
#define NODELIST_H

#include <iostream>
using namespace std;

template <class T>
class Node{
  private:
  T data;
  Node<T>* next = nullptr;
  public:
  Node(T, Node<T>*);
  Node(T);
  ~Node();
  // Cambiamos a retornar referencia:
  T& getData();
  const T& getData() const;
  void setData(T);
  Node<T>* getNext();
  void setNext(Node<T>*);
  void print();
};

using namespace std;

template<class T>
Node<T>::Node(T data, Node<T>* next): data(data), next(next){
}

template<class T>
Node<T>::Node(T data): data(data), next(nullptr){
}

template<class T>
Node<T>::~Node(){
    this->next = nullptr;
}
template<class T>
T& Node<T>::getData(){
    return this->data;
}

template<class T>
const T& Node<T>::getData() const {
    return this->data;
}

template<class T>
void Node<T>::setData(T data){
    this->data = data;
}

template<class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template<class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template<class T>
void Node<T>::print(){
   cout<<this->data<<endl;
   cout<<this->next<<endl;
}

#endif