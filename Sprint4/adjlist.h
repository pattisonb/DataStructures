#ifndef ADJLIST_H
#define ADJLIST_H
#include "linkedlist.h"
template <class T>
class AdjNode {
    template <class U> friend class AdjList;
     template <class U> friend class Iterator;
private:
    LinkedList<T>* list;
    T data;
    AdjNode* next;
public:
    AdjNode(LinkedList<T>* x, T d = 0, AdjNode* n = nullptr) : list(x), data(d), next(n) {}
};

template <class T>
class AdjList
{
private:
    AdjNode<T>* front;
    AdjNode<T>* back;
    int size = 0;
    void copyList(const AdjList<T> &);
    void clear();

public:
    typedef Iterator<T> iterator;

    AdjList();
    AdjList(T, LinkedList<T>);
    AdjList(AdjList<T>&);
    ~AdjList();
    AdjList<T> operator= (const AdjList<T>&);

    void push_back(AdjNode<T>&);
    LinkedList<T>* getLinkedList(const T&);
};

template <class T>
AdjList<T>::AdjList() {
    front = new AdjNode<T>;
    back = new AdjNode<T>;
}

template <class T>
AdjList<T>::AdjList(T data, LinkedList<T> path) {
    size = 1;
    AdjNode<T> *node = new AdjNode<T>(&path, data);
    front = node;
    node->next = nullptr;
    back = nullptr;
}

template <class T>
AdjList<T>::AdjList(AdjList<T>& copyList) {
    copyList();
}

template <class T>
AdjList<T>::~AdjList<T>() {
    clear();
}

template <class T>
AdjList<T> AdjList<T>::operator= (const AdjList<T>& copyList) {
    if (&copyList != this) {
        clear();
        copyList(copyList());
    }
    return *this;
}

template <class T>
void AdjList<T>::copyList(const AdjList<T>& copyList) {
    size = copyList.size;
    if (size == 0) {
        front = nullptr;
        back = nullptr;
        return;
    }
    front = new AdjNode<T>(copyList);
    //back = front;

    AdjNode<T>* copyNode = copyList.front->next;

    while (copyNode) {
        back->next = new AdjNode<T>(copyList);
        back = back->next;
        copyNode = copyNode->next;
    }
}

template <class T>
void AdjList<T>::clear() {
    AdjNode<T>* curr;
    curr = front;
    while (curr != nullptr) {
        curr->list->clear();
        //delete front;
        front = curr;
        curr = curr->next;
    }
}

template <class T>
void AdjList<T>::push_back(AdjNode<T>& newNode) {
    if (size == 0){
        front = back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
}

template <class T>
LinkedList<T>* AdjList<T>::getLinkedList(const T& find) {
    AdjNode<T>* curr;
    curr = front;
    while (curr != nullptr) {
        if (curr->data == find) {
            return curr->list;
        }
        curr = curr->next;
    }
}
#endif // ADJLIST_H
