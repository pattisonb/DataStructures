#ifndef DSVECTOR_H
#define DSVECTOR_H

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

        DSVector<T>& operator= (const DSVector<T>&);

        T& operator[] (const int);

        int size();
        int getCapacity();
        void resize();
        void push_back(const T&);
        void pop_back();
        bool empty();

        ~DSVector();
};
#endif // DSVECTOR_H
