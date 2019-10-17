#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "sorter.h"
using namespace std;
using namespace chrono;

int addressOfSmallestTime (int arr[], int n);
int addressOfLargestTime (int arr[], int n);
void alphabetizedPrint(vector <string>);
void swap (string* xp, string* yp);

int main()
{
   Sorter<int>* exp [5];
   vector <string> print = {"MysterySortA is ", "MysterySortB is ", "MysterySortC is ", "MysterySortD is ", "MysterySortE is " };
   vector <string> alphabetPrint;

   // [0] = Quick Sort, [1] = Selection Sort, [2] = Insertion Sort, [3] = Bubble Sort, [4] = Merge Sort
   int times [5];

   exp[0] = new MysterySorterA<int>;
   exp[1] = new MysterySorterB<int>;
   exp[2] = new MysterySorterC<int>;
   exp[3] = new MysterySorterD<int>;
   exp[4] = new MysterySorterE<int>;


   //testing with vector of 100 random numbers to figure out with is quickSort

   srand(time(0));
   int b = rand() % 100;

   vector<int> data;
   for (int i = 0; i < 100; i++) {
       data.push_back(b);
       b = rand() % 100;
   }

   for (int i = 0; i < 5; i++) {
       exp[i]->setData(data);
   }

   for (int i = 0; i < 5; i++) {
       auto t1 = high_resolution_clock::now();
       exp[i]->sort();
       auto t2 = high_resolution_clock::now();
       auto elapsedTime = duration_cast <microseconds>( t2 - t1 ).count();
       times[i] = elapsedTime;
       //cout << times[i] << endl;
   }

   swap(exp[addressOfSmallestTime(times, 5)], exp[4]);
   swap(print[addressOfSmallestTime(times, 5)], print[4]);
   alphabetPrint.push_back(print[4] + "QuickSort");
   //now only test the 4 unknown vectors

   //testing with 100 elements in increasing order
   vector<int> data1;

   for (int i = 0; i < 100; i++) {
       data1.push_back(i);
   }
   for (int i = 0; i < 4; i++) {
       exp[i]->setData(data1);
   }
   //this one tests for merge sort
   //cout << "100 numbers in ascending order" << endl;
   for (int i = 0; i < 4; i++) {
       auto t1 = high_resolution_clock::now();
       exp[i]->sort();
       auto t2 = high_resolution_clock::now();
       auto elapsedTime = duration_cast <microseconds>( t2 - t1 ).count();
       times[i] = elapsedTime;
       //cout << times[i] << endl;
   }
   swap(exp[addressOfLargestTime(times, 4)], exp[3]);
   swap(print[addressOfLargestTime(times, 4)], print[3]);
   alphabetPrint.push_back(print[3] + "MergeSort");

   //testing for bubblesort
   //bubble sort will perform much worse than insertion and selection
   vector<int> data2;

   for (int i = 0; i < 1000; i++) {
       data2.push_back(b);
       b = rand() % 100;
   }
   for (int i = 0; i < 3; i++) {
       exp[i]->setData(data2);
   }

   for (int i = 0; i < 3; i++) {
       auto t1 = high_resolution_clock::now();
       exp[i]->sort();
       auto t2 = high_resolution_clock::now();
       auto elapsedTime = duration_cast <microseconds>( t2 - t1 ).count();
       times[i] = elapsedTime;
       //cout << times[i] << endl;
   }
   swap(exp[addressOfLargestTime(times, 3)], exp[2]);
   swap(print[addressOfLargestTime(times, 3)], print[2]);
   alphabetPrint.push_back(print[2] + "BubbleSort");

   vector<int> data3;

   for (int i = 0; i < 1000; i++) {
       data3.push_back(i);
   }
   for (int i = 0; i < 2; i++) {
       exp[i]->setData(data3);
   }

   for (int i = 0; i < 2; i++) {
       auto t1 = high_resolution_clock::now();
       exp[i]->sort();
       auto t2 = high_resolution_clock::now();
       auto elapsedTime = duration_cast <microseconds>( t2 - t1 ).count();
       times[i] = elapsedTime;
       //cout << times[i] << endl;
   }
   swap(exp[addressOfLargestTime(times, 2)], exp[1]);
   swap(print[addressOfLargestTime(times, 2)], print[1]);

   alphabetPrint.push_back(print[1] + "SelectionSort");
   alphabetPrint.push_back(print[0] + "InsertionSort");

   alphabetizedPrint(alphabetPrint);
}

int addressOfSmallestTime (int arr[], int n) {
   int smallest = arr[0];
   for (int i = 0; i < n; i++) {
       if (smallest > arr[i]) {
           smallest = arr[i];
       }
   }
   int address;
   for (int i = 0; i < n; i++) {
       if (smallest == arr[i]) {
           address = i;
       }
   }
   return address;
}

int addressOfLargestTime (int arr[], int n) {
   int largest = arr[0];
   for (int i = 0; i < n; i++) {
       if (largest < arr[i]) {
           largest = arr[i];
       }
   }
   int address;
   for (int i = 0; i < n; i++) {
       if (largest == arr[i]) {
           address = i;
       }
   }
   return address;
}

void swap(string *xp, string *yp)
{
   string temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void alphabetizedPrint(vector <string> x) {
   int i, j, min_idx;
   int n = x.size();

   // One by one move boundary of unsorted subarray
   for (i = 0; i < n-1; i++)
   {
       // Find the minimum element in unsorted array
       min_idx = i;
       for (j = i+1; j < n; j++)
           if (x[j] < x[min_idx])
               min_idx = j;

       // Swap the found minimum element with the first element
       swap(&x[min_idx], &x[i]);
   }

   for (int i = 0; i < n; i++) {
       cout << x[i] << endl;
   }
}










