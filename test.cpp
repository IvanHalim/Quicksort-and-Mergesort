#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.hpp"

using std::cout;
using std::endl;
using std::srand;
using std::time;

void display(vector<int> vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main() {

    // Initialize the seed for the random number generator
    srand(time(0));

    // Create an array of size 10 with random numbers between 1 and 10
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 10 + 1);
    }

    // Create copies of array arr
    vector<int> mergesort(arr.begin(), arr.end());
    vector<int> quicksort(arr.begin(), arr.end());
    vector<int> heapsort(arr.begin(), arr.end());

    // Sort the arrays
    sort mySort;
    mySort.mergesort(mergesort, 0, mergesort.size()-1);
    mySort.quicksort(quicksort, 0, quicksort.size()-1);
    mySort.heapsort(heapsort, 0, heapsort.size());

    // Display the arrays
    display(arr);
    display(mergesort);
    display(quicksort);
    display(heapsort);

    return 0;
}