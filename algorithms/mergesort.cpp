#include <vector>
#include <limits>

using std::vector;
using std::numeric_limits;

void merge(vector<int>&, int, int, int);

void mergesort(vector<int> &arr, int low, int high) {

    if (low < high) {

        // Same as (low + high)/2, but avoids overflow for
        // large low and high
        int mid = low + (high-low)/2;

        // Sort first and second halves
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

// Merges two subarray of arr[]
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void merge(vector<int> &arr, int low, int mid, int high) {
    int half1 = mid - low + 1;
    int half2 = high - mid;

    // create temp arrays
    int array1[half1 + 1];
    int array2[half2 + 1];

    // Copy data to temp arrays L[] and R[]
    for (int i=0;i<half1;i++)
        array1[i] = arr[i+low];
    for (int i=0;i<half2;i++)
        array2[i] = arr[i+half1+low];

    // Set the last element of the subarrays to be a very large number
    array1[half1] = numeric_limits<int>::max();
    array2[half2] = numeric_limits<int>::max();

    // Merge the temp arrays back into arr[low..high]
    int i = 0;  // Initial index of first subarray
    int j = 0;  // Initial index of second subarray
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
