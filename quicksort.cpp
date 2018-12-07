int partition(vector<int>&, int, int);

// A utility function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
void quicksort(vector<int> &arr, int low, int high) {

    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[high];  // Pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }

    }
    swap(arr[i+1], arr[high]);
    return i+1;
}