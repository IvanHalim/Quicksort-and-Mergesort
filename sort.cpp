#include "sort.hpp"
#include <limits>
#include <algorithm>

using std::numeric_limits;
using std::upper_bound;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(vector<int> &arr, int low, int mid, int high) {

    int half1 = mid - low + 1;
    int half2 = high - mid;

    int array1[half1 + 1];
    int array2[half2 + 1];

    for (int i=0;i<half1;i++)
        array1[i] = arr[i+low];
    for (int i=0;i<half2;i++)
        array2[i] = arr[i+half1+low];

    array1[half1] = numeric_limits<int>::max();
    array2[half2] = numeric_limits<int>::max();

    int i = 0;
    int j = 0;
    for (int k=low;k<=high;k++) {
        if (array1[i] <= array2[j]) {
            arr[k] = array1[i];
            i++;
        } else {
            arr[k] = array2[j];
            j++;
        }
    }
}

void sort::mergesort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = low + (high-low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void sort::quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

void heapify_down(vector<int> &arr, int size, int parent) {

    int largest = parent;
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;

    if (left_child < size && arr[left_child] > arr[largest])
        largest = left_child;
    if (right_child < size && arr[right_child] > arr[largest])
        largest = right_child;

    if (parent != largest) {
        swap(arr[parent], arr[largest]);
        heapify_down(arr, size, largest);
    }
}

void sort::heapsort(vector<int> &arr, int low, int high) {

    int size = high + 1;
    int root = low;

    for (int i = size/2-1; i >= root; i--) {
        heapify_down(arr, size, i);
    }

    for (int i = size-1; i >= root; i--) {
        swap(arr[root], arr[i]);
        heapify_down(arr, i, root);
    }
}

int sort::binary_search(vector<int> arr, int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

void sort::insert_sorted(vector<int>& arr, int value) {
    arr.insert(upper_bound(arr.begin(), arr.end(), value), value);
}