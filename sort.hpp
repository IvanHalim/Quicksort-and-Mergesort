#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

using std::vector;

struct sort {
    static void        quicksort(vector<int>&, int, int);
    static void        mergesort(vector<int>&, int, int);
    static void        heapsort(vector<int>&, int, int);
    static int         binary_search(vector<int>, int, int, int);
    static void        insert_sorted(vector<int>&, int);
    static bool        remove(vector<int>&, int);
    static vector<int> set_union(vector<int>, vector<int>);
    static vector<int> intersection(vector<int>, vector<int>);
    static vector<int> symm_diff(vector<int>, vector<int>);
};
#endif