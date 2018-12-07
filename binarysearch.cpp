#include <vector>

using std::vector;

int binary_search(vector<int> arr, int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high-low)/2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;

        // If the element is smaller than mid, then
        // it can only be present in left subarray
        } else if (arr[mid] > x) {
            high = mid-1;

        // Else the element can only be present
        // in the right subarray
        } else {
            low = mid+1;
        }
    }

    // If nothing is found then return -1
    return -1;
}