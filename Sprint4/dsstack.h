#ifndef DSSTACK_H
#define DSSTACK_H

#include "linkedlist.h"

template <typename T>

class DSStack {

private:
   LinkedList <T> data;
   int size = 0;

public:
   void push(T);
   T pop();
   T peek();
   bool isEmpty();
   bool contains(T);
};

template <typename T>
void DSStack<T>::push (T n) {
    ++size;
   data.insertAtFront(n);
}

template <typename T>
T DSStack<T>::pop() {
    --size;
   T temp = data.peekFront();
   data.deleteFront();
   return temp;
}

template <typename T>
T DSStack<T>::peek() {
   return data.peekFront();
}

template <typename T>
bool DSStack<T>::isEmpty() {
   return size == 0;
}

template <typename T>
bool DSStack<T>::contains(T x){
    return data.contains(x);
}
#endif //SPRINT4_DSSTACK_H

