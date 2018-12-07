#include <vector>

using std::vector;

// A utility function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// This is the heapify_down function of a maximizing heap
void heapify_down(vector<int> &arr, int size, int parent) {

    // First we assume that the parent node is the largest
    int largest = parent;
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;

    // Next we're going to check if the child nodes are larger than the parent
    if (left_child < size && arr[left_child] > arr[largest])
        largest = left_child;
    if (right_child < size && arr[right_child] > arr[largest])
        largest = right_child;

    /*
     * If the parent node is not the largest node
     * We swap the value of the parent node with the value of the largest node
     * We repeat this process until we reach the bottom of the heap
     */
    if (parent != largest) {
        swap(arr[parent], arr[largest]);
        heapify_down(arr, size, largest);
    }
}

// Main function to do heap sort
void heapsort(vector<int> &arr, int root, int size) {

    /*
     * First we convert array arr[] into a heap using our heapify_down function
     * Bottom-up from the first non-leaf node to the root of the heap
     * (size/2-1) is the first non-leaf node
     */
    for (int i = size/2-1; i >= root; i--) {
        heapify_down(arr, size, i);
    }

    /*
     * Next we're going to extract the maximum value of the heap
     * By swapping the value at the root of the heap with the value at the end of the heap
     * Similar to how we remove the root value from a binary heap
     * Making sure that we heapify_down the unsorted array after each extraction
     */
    for (int i = size-1; i >= root; i--) {
        swap(arr[root], arr[i]);
        heapify_down(arr, i, root);
    }
}