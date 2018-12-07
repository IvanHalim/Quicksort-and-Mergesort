#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

using std::vector;

struct sort {
        void        quicksort(vector<int>&, int, int);
        void        mergesort(vector<int>&, int, int);
        void        heapsort(vector<int>&, int, int);
        int         binary_search(vector<int>, int, int, int);
        void        insert_sorted(vector<int>&, int);
        bool        remove(vector<int>&, int);
        vector<int> set_union(vector<int>, vector<int>);
        vector<int> intersection(vector<int>, vector<int>);
        vector<int> symm_diff(vector<int>, vector<int>);
};
#endif