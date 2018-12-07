#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <limits>

using std::vector;

class sort {
    public:
        sort()  {};
        void    quicksort(vector<int>&, int, int);
        void    mergesort(vector<int>&, int, int);
        void    heapsort(vector<int>&, int);
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(vector<int> &arr, int low, int mid, int high) {

    int half1 = mid - low + 1;
    int half2 = high - mid;

    int array1[half1];
    int array2[half2];

    for (int i=0;i<half1;i++)
        array1[i] = arr[i+low];
    for (int i=0;i<half2;i++)
        array2[i] = arr[i+half1+low];

    int i = 0;
    int j = 0;
    for (int k=low;k<=high;k++) {
        if (j >= half2) {
            arr[k] = array1[i];
            i++;
        } else if (array1[i] <= array2[j]) {
            arr[k] = array1[i];
            i++;
        } else if (i >= half1) {
            arr[k] = array2[j];
            j++;
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

void sort::heapsort(vector<int> &arr, int size) {

    for (int i = size/2-1; i >= 0; i--) {
        heapify_down(arr, size, i);
    }

    for (int i = size-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify_down(arr, i, 0);
    }
}

#endif