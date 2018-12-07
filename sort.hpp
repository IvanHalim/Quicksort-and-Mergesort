#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

using std::vector;

class sort {
    public:
        sort()  {};
        void    quicksort(vector<int>&, int, int);
        void    mergesort(vector<int>&, int, int);
        void    heapsort(vector<int>&, int, int);
        int     binary_search(vector<int>, int, int, int);
};
#endif