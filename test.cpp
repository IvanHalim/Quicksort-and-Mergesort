#include <iostream>
#include "sort.hpp"

using std::cout;
using std::endl;

void display(vector<int> vect) {
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{10, 7, 8, 9, 1, 5};
    sort mySort;
    vector<int> mergesort(arr.begin(), arr.end());
    vector<int> quicksort(arr.begin(), arr.end());
    vector<int> heapsort(arr.begin(), arr.end());
    mySort.mergesort(mergesort, 0, mergesort.size()-1);
    mySort.quicksort(quicksort, 0, quicksort.size()-1);
    mySort.heapsort(heapsort, heapsort.size());
    display(mergesort);
    display(quicksort);
    display(heapsort);
    display(arr);
    mySort.quicksort(arr, 0, arr.size()-1);
    display(arr);

    return 0;
}