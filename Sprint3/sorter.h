#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

template <typename T>
class Sorter {
protected:
   std::vector<T> data;

public:
   Sorter() {}
   Sorter(T& x):data(x) {}
   void setData (const std::vector<T>& x) {
       data = x;
   }
   virtual void sort() = 0;
};


template <typename T>
class MysterySorterA : public Sorter<T> {
public:
   virtual void sort() {
       int i, j;
       int n = this->data.size();
       bool swapped;
       for (i = 0; i < n-1; i++)
       {
           swapped = false;
           for (j = 0; j < n-i-1; j++)
           {
               if (this->data[j] > this->data[j+1])
               {
                   swap(&this->data[j], &this->data[j+1]);
                   swapped = true;
               }
           }

           // IF no two elements were swapped by inner loop, then break
           if (swapped == false)
               break;
       }
       //std::cout << "Mystery Sorter A : Bubble sort" << std::endl;
   }
   void swap(T *xp, T *yp)
   {
       T temp = *xp;
       *xp = *yp;
       *yp = temp;
   }
};

template <typename T>
class MysterySorterB : public Sorter<T> {
public:
   virtual void sort() {
       int i, key, j;
       int n = this->data.size();
       for (i = 1; i < n; i++)
       {
           key = this->data[i];
           j = i - 1;
           while (j >= 0 && this->data[j] > key)
           {
               this->data[j + 1] = this->data[j];
               j = j - 1;
           }
           this->data[j + 1] = key;
       }
       //std::cout << "Mystery Sorter B : Insertion sort" << std::endl;
   }
};

template <typename T>
class MysterySorterC : public Sorter<T> {
public:
   virtual void sort() {
       this->data = mergeSort(this->data);
       //std::cout << "Mystery Sorter C : Merge Sort" << std::endl;
   }
   std::vector<int> merge(std::vector<int> left, std::vector<int> right)
   {
       std::vector<int> result;
       while ((int)left.size() > 0 || (int)right.size() > 0) {
           if ((int)left.size() > 0 && (int)right.size() > 0) {
               if ((int)left.front() <= (int)right.front()) {
                   result.push_back((int)left.front());
                   left.erase(left.begin());
               }
               else {
                   result.push_back((int)right.front());
                   right.erase(right.begin());
               }
           }  else if ((int)left.size() > 0) {
               for (int i = 0; i < (int)left.size(); i++)
                   result.push_back(left[i]);
               break;
           }  else if ((int)right.size() > 0) {
               for (int i = 0; i < (int)right.size(); i++)
                   result.push_back(right[i]);
               break;
           }
       }
       return result;
   }
   std::vector<int> mergeSort(std::vector<int> m)
   {
       if (m.size() <= 1)
           return m;

       std::vector<int> left, right, result;
       int middle = ((int)m.size()+ 1) / 2;

       for (int i = 0; i < middle; i++) {
           left.push_back(m[i]);
       }

       for (int i = middle; i < (int)m.size(); i++) {
           right.push_back(m[i]);
       }

       left = mergeSort(left);
       right = mergeSort(right);
       result = merge(left, right);

       return result;
   }
};

template <typename T>
class MysterySorterD : public Sorter<T> {
public:
   virtual void sort() {
       quickSort(this->data, 0, this->data.size());
       //std::cout << "Mystery Sorter D : Quick Sort" << std::endl;
   }
   void swap(T* a, T* b)
   {
       T t = *a;
       *a = *b;
       *b = t;
   }

   /* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
   int partition (std::vector<T> &arr, int low, int high)
   {
       int pivot = arr[high]; // pivot
       int i = (low - 1); // Index of smaller element

       for (int j = low; j <= high - 1; j++)
       {
           // If current element is smaller than the pivot
           if (arr[j] < pivot)
           {
               i++; // increment index of smaller element
               swap(&arr[i], &arr[j]);
           }
       }
       swap(&arr[i + 1], &arr[high]);
       return (i + 1);
   }

   /* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
   void quickSort(std::vector<T> &arr, int low, int high)
   {
       if (low < high)
       {
           /* pi is partitioning index, arr[p] is now
           at right place */
           int pi = partition(arr, low, high);

           // Separately sort elements before
           // partition and after partition
           quickSort(arr, low, pi - 1);
           quickSort(arr, pi + 1, high);
       }
   }
};

template <typename T>
class MysterySorterE : public Sorter<T> {
public:
   virtual void sort() {
       this->data = selectionSort(this->data, this->data.size());
       //std::cout << "Mystery Sorter E : Selection Sort" << std::endl;
   }
   void swap(T *xp, T *yp)
   {
       T temp = *xp;
       *xp = *yp;
       *yp = temp;
   }

   std::vector<T> selectionSort(std::vector<T> arr, int n)
   {
       int i, j, min_idx;

       // One by one move boundary of unsorted subarray
       for (i = 0; i < n-1; i++)
       {
           // Find the minimum element in unsorted array
           min_idx = i;
           for (j = i+1; j < n; j++)
               if (arr[j] < arr[min_idx])
                   min_idx = j;

           // Swap the found minimum element with the first element
           swap(&arr[min_idx], &arr[i]);
       }
       return arr;
   }
};

#endif //SORTINGFUN_SORTER_H




