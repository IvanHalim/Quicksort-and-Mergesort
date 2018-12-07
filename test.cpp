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
    srand(time(0));
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 10 + 1);
    }
    sort mySort;
    vector<int> mergesort(arr.begin(), arr.end());
    vector<int> quicksort(arr.begin(), arr.end());
    vector<int> heapsort(arr.begin(), arr.end());
    mySort.mergesort(mergesort, 0, mergesort.size()-1);
    mySort.quicksort(quicksort, 0, quicksort.size()-1);
    mySort.heapsort(heapsort, heapsort.size());
    display(arr);
    display(mergesort);
    display(quicksort);
    display(heapsort);
    mySort.quicksort(arr, 0, arr.size()-1);
    display(arr);

    return 0;
}