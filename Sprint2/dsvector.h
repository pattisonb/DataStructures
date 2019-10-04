#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>

using namespace std;

template <typename T>

class DSVector {

    private:
        int length;
        int capacity;
        T* arr;

    public:
        DSVector();
        DSVector(const int);
        DSVector(const DSVector<T>&);
        ~DSVector();

        DSVector<T>& operator= (const DSVector<T>&); //==
        bool operator== (const DSVector<T>&);

        T& operator[] (const int);

        int getSize();
        int getCapacity();
        void resize();
        void push_back(const T&);
        void pop_back();
        bool isEmpty();
        int countDuplicate(const T&);
        void print();
};

template <typename T>
DSVector<T>::DSVector() {
    length = 0;
    capacity = 10;
    arr = new T[capacity];
}

template <typename T>
DSVector<T>::DSVector(const int a) {
    length = a;
    capacity = a + 10;
    arr = new T[capacity];
}

template <typename T>
DSVector<T>::DSVector(const DSVector<T>& a) {
    length = a.length;
    capacity = a.capacity;
    arr = new T[capacity];
    for (int i = 0; i < length; i++) {
        arr[i] = a.arr[i];
    }
}

template <typename T>
DSVector<T>::~DSVector() {
    delete [] arr;
}

template <typename T>
DSVector<T>& DSVector<T>::operator= (const DSVector<T>& a) {
    if (arr != a.arr) {
        if (arr != nullptr) {
            delete [] arr;
        }
        length = a.length;
        capacity = a.capacity;
        arr = new T[a.length];
        for (int i = 0; i < length; i++) {
            arr[i] = a.arr[i];
        }
    }
    return *this;
}

template <typename T>
bool DSVector<T>::operator== (const DSVector<T>& a) {
    if (length != a.length) {
        return false;
    }
    else {
        for (int i = 0; i < length; i++) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
        }
        return true;
    }
}

template <typename T>
T& DSVector<T>::operator[] (const int a) {
    return arr[a];
}


template <typename T>
int DSVector<T>::getSize() {
    return length;
}

template <typename T>
int DSVector<T>::getCapacity() {
    return capacity;
}

template <typename T>
void DSVector<T>::resize() {
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < length; i++) {
        temp[i] = arr[i];
    }
    delete [] this->arr;
    this->arr = temp;
}

template <typename T>
void DSVector<T>::push_back(const T& newData) {
    if (length == capacity) {
    resize();
    }
    arr[length] = newData;
    length++;
}

template <typename T>
void DSVector<T>::pop_back() {
    length--;
}

template <typename T>
bool DSVector<T>::isEmpty() {
        if (length == 0) {
            return true;
        }
    return false;
}

template <typename T>
int DSVector<T>::countDuplicate(const T& ele) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (ele == arr[i]) {
            count++;
        }
    }
    return count;
}

template <typename T>
void DSVector<T>::print() {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}
#endif // DSVECTOR_H
