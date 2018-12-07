#include <vector>

using std::vector;

int binary_search(vector<int> arr, int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high-low)/2;

        // If the value is present at the middle itself
        if (arr[mid] == value) {
            return mid;

        // If the value is smaller than mid, then
        // it can only be present in left subarray
        } else if (arr[mid] > value) {
            high = mid-1;

        // Else the value can only be present
        // in the right subarray
        } else {
            low = mid+1;
        }
    }

    // If nothing is found then return -1
    return -1;
}