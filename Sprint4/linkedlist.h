#ifndef SPRINT4_LINKEDLIST_H
#define SPRINT4_LINKEDLIST_H

//#include "dsstack.h"

template <class T>
class ListNode {
   template <class U> friend class LinkedList;
    template <class U> friend class Iterator;
    friend class AdjList;

private:
   ListNode* next;
   ListNode* previous;
   T data;

public:
   ListNode() : next(nullptr), previous(nullptr) {}
   ListNode(T val) : next(nullptr), previous(nullptr), data(val){}
   ListNode(const ListNode<T>& d) : data(d.data), next(nullptr), previous(nullptr) {}
};


template <class T>
class Iterator {
   template <class U> friend class LinkedList;

private:
   ListNode<T>* end;

public:
      ListNode<T>* pointer;
   Iterator(ListNode<T>* ptr = nullptr, ListNode<T>* last = nullptr) : pointer(ptr), end(last) {}
   //derefence the iterator
   T& operator*() {return pointer->data; }
   //need pre and post increments
   Iterator<T>& operator++() {
       if (pointer->next == nullptr) {
           end = pointer;
       }
       pointer = pointer->next;
       return *this;
   }
   Iterator<T>& operator++(int) {
       Iterator<T> temp(*this);
       if (pointer->next == nullptr) {
           end = pointer;
       }
       pointer = pointer->next;
       return temp;
   }
   //pre and post decrements
   Iterator<T>& operator--() {
       if (pointer->next == nullptr) {
           end = pointer;
       }
       else {
           pointer = pointer->previous;
       }
       return *this;
   }
   Iterator<T>& operator--(int) {
       Iterator<T> temp(*this);
       if (pointer->next == nullptr) {
           end = pointer;
       }
       else {
           pointer = pointer->previous;
       }
       return temp;
   }
};

template <class T>
class LinkedList {
    template <class U> friend class DSStack;
private:
   ListNode<T> *front;
   ListNode<T> *back;
   int size;
public:
   LinkedList();
   LinkedList(const T&);
   LinkedList(const LinkedList<T>&);
   ~LinkedList();
   LinkedList<T>& operator= (const LinkedList<T>&);

   typedef Iterator<T> iterator;

   void copyList(const LinkedList<T>&);
   void clear();
   bool isEmpty();
   int getSize();
   T peekFront();

   void insertAtFront(T&);
   void insertAtEnd(T&);
   void deleteFront();
   void deleteBack();

   Iterator<T> erase(Iterator<T>);
   Iterator<T> insert(Iterator<T>, const T&); //inserts before the element
   Iterator<T> begin() {return iterator(front);}

   bool contains(T);
};

template <class T>
LinkedList<T>::LinkedList(){
   front = new ListNode<T>();
   back = new ListNode<T>();
   size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const T & node) {
   front = new ListNode<T>(node);
   back = new ListNode<T>(node);
   size = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & newList) {
   copyList(newList);
}

template <class T>
LinkedList<T>::~LinkedList() {
   clear();
   delete front;
   //delete back;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &newList) {
   if (&newList != this) {
       clear();
       copyList(newList);
   }
   return *this;
}

template <class T>
void LinkedList<T>::copyList(const LinkedList<T> & oldList) {
   size = oldList.size;

   if (size == 0) {
       front = nullptr;
       back = nullptr;
       return;
   }

   front = new ListNode<T>(oldList.front->data); //creating the new head node
   back = front;

   ListNode<T>* copyNode = oldList.front->next; //copyNode points to the next node to be copied

   while (copyNode) { //copying remainder of list until copyNode is null
       back->next = new ListNode<T>(copyNode->data); //creating new node to add to copied list
       back->next->previous = back;
       back = back->next;
       copyNode = copyNode->next;
   }
}

template <class T>
void LinkedList<T>::clear() {
   ListNode<T>* curr = front;
   while (curr != nullptr) {
       curr = curr->next;
       delete front;
       front = curr;
   }
   size = 0;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    if ((front == nullptr && back == nullptr) || size == 0) {
        return true;
    }
    return false;
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
T LinkedList<T>::peekFront() {
   return front->data;
}

template <class T>
void LinkedList<T>::insertAtFront(T &data) {
   ListNode<T>* newNode = new ListNode<T>(data);
   if (!front) { //if list is empty
       front = back = newNode;
   }

   else {
       //if list only has 1 element
       if (size == 1) {
           back = front;
       }
     newNode->next = front;
     newNode->previous = nullptr;
     front->previous = newNode;
     front = newNode;
   }
   ++size;
}

template <class T>
void LinkedList<T>::insertAtEnd(T &data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if (size == 0) { //if list is empty
        front = back = newNode;
    }

    else {
        //if list only has 1 element
        if (size == 1) {
            back = front;
        }
      newNode->previous = back;
      newNode->next = nullptr;
      back->next = newNode;
      back = newNode;
    }
    ++size;
}

template <class T>
void LinkedList<T>::deleteFront() {
   if (size == 0) {

   }
   ListNode<T>* temp = front;
   if (front == back) { //if the size is 1
       clear();
       return;
   }
   else {
       front = front->next;
       front->previous = nullptr;
       delete temp;
   }
   --size;
}

template <class T>
void LinkedList<T>::deleteBack() {
   back->previous->next = back->next;
   delete back;
   --size;
}

template <class T>
Iterator<T> LinkedList<T>::erase(Iterator<T> itr) {
   --size;
   Iterator<T> result(itr.pointer->next);
   //run different options based on the size of the list
   if (itr.pointer == front && front == back) { //one node
       front = nullptr;
       back = nullptr;
   }
   //removing the first element
   if (itr.pointer == front) {
       front = front->next;
       front->previous = nullptr;
   }
   //removing the last element
   if (itr.pointer == back) {
       back = back->previous;
       back->next = nullptr;
   }
   //normal case
   else {
       itr.pointer->previous->next = itr.pointer->next;
       itr.pointer->next->previous = itr.pointer->previous;
   }
   delete itr.pointer;
   return result;
}

template <class T>
Iterator<T> LinkedList<T>::insert(Iterator<T> itr, const T& value) {
   ++size;
   ListNode<T>* node = new ListNode<T>(value);
   node->previous = itr.pointer->previous;
   node->next = itr.pointer;
   itr.pointer->previous = node;
   //if the new node is now the front
   if (itr.pointer == front) {
       front = node;
   }
   else {
       node->previous->next = node;
   }
   return Iterator<T> (node); //set the iterator to point at the new element
}

template <class T>
bool LinkedList<T>::contains(T x){
    ListNode<T>* current = new ListNode<T>;
    current = front;
    while (current != nullptr) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}
#endif //SPRINT4_LINKEDLIST_H


