// you have an array that is sorted in ascending order, and rotated by unknown amount:
//      e.g. [8 9 10 1 2 3 4 5 6 7]
// write an efficient algorithm that gives an index for a given value.

#include <cassert>
#include <iostream>
using namespace std;

int find_element(const int * arr, int n, int v) {
    // find the starting point such that arr[i] < arr[(i+1) % n]
    // from there, run another binary search to find i
    // we assume we always have such element in the array

    // first, we want find i s.t. arr[i] > arr[(i + 1) % n]
    int l = 0;
    int r = n;
    while (r - l != 1) {
        // e.g.
        // 2  3  0  1
        // 0  1  2  3  4
        // l     m     r
        // l  m  r
        //    l  r
        int m = (l + r) / 2;
        if (arr[l] < arr[m]) {
            l = m;
        }
        else {
            r = m;
        }
    }
    r = r % n;

    // now search
    int i = 0;
    int j = n;
    while (j - i != 0) {
        int k = (i + j) / 2;
        if (arr[(r + k) % n] == v) {
            return (r + k) % n;
        }
        if (i == k) {
            break;
        }
        if (arr[(r + k) % n] < v) {
            i = k;
        }
        else {
            j = k;
        }
    }

    return -1;
}

int main(int argc, const char ** argv) {
    {
        int arr[] = {0, 1, 2, 3, 4};
        int n = sizeof(arr) / sizeof(int);
        assert(find_element(arr, n, 4) == 4);
        assert(find_element(arr, n, 0) == 0);
    }
    {
        int arr[] = {0, 0, 0, 0, 0};
        int n = sizeof(arr) / sizeof(int);
        assert(arr[find_element(arr, n, 0)] == 0);
    }
    {
        int arr[] = {0, 0, 1, 0, 0};
        int n = sizeof(arr) / sizeof(int);
        assert(arr[find_element(arr, n, 1)] == 1);
    }
    {
        int arr[] = {5, 0, 1, 2, 3, 4};
        int n = sizeof(arr) / sizeof(int);
        assert(find_element(arr, n, 4) == 5);
        assert(find_element(arr, n, 0) == 1);
        assert(find_element(arr, n, 5) == 0);
        assert(find_element(arr, n, 6) == -1);
    }
    {
        int arr[] = {4, 5, 6, 0, 1, 2, 3};
        int n = sizeof(arr) / sizeof(int);
        assert(find_element(arr, n, 4) == 0);
        assert(find_element(arr, n, 0) == 3);
        assert(find_element(arr, n, 5) == 1);
        assert(find_element(arr, n, 6) == 2);
        assert(find_element(arr, n, 3) == 6);
    }
    return 0;
}