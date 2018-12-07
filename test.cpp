#include <iostream>
#include "sort.hpp"

using std::cout;
using std::endl;

void display(vector<int> vect) {
    for (int x : vect)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr{10, 7, 8, 9, 1, 5};
    sort mySort;
    vector<int> mergesort = mySort.mergesort(arr, 0, arr.size()-1);
    vector<int> quicksort = mySort.quicksort(arr, 0, arr.size()-1);
    vector<int> heapsort = mySort.heapsort(arr, arr.size());
    display(mergesort);
    display(quicksort);
    display(heapsort);
    display(arr);

    return 0;
}