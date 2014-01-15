// career cup 150
// 2.1. array a1, a2, ..., an, b1, b2, ..., bn.
//      change it to a1, b1, a2, b2, ..., an, bn.

// if we have another empty array, it will be very easy.
// however it will take O(n) size. not good.
// would there be a better way?

// a1 a2 a3 a4 b1 b2 b3 b4
// a1 b1 a2 b2 a3 b3 a4 b4
// a2 -> a3 -> b1 -> a2
// a4 -> b3 -> b2 -> a4

// 0 1 2 3 4 5 6 7 8 9
// 0 5 1 6 2 7 3 8 4 9
// a1 a2 a3 a4 a5 b1 b2 b3 b4 b5
// a1 b1 a2 b2 a3 b3 a4 b4 a5 b5
// a2 -> a3 -> a5 -> b4 -> b3 -> b1 -> a2
// a4 -> b2
// 1 2 4 8 7 5
// 3 

// if i know some value that is NOT in the array, then I can solve it.
// if all the values are positive, then I can solve it O(1) size.

#include <iostream>
using namespace std;

void mix(int * arr, int n) {
    int m = n / 2;
    for (int i = 0; i < n; ++i) {
        int v = arr[i];
        int j = i;
        while (v > 0) {
            int k = (j < m) ? j * 2 : (j - m) * 2 + 1;
            int t = arr[k];
            arr[k] = -v;
            v = t;
            j = k;
        }
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = -arr[i];
    }
}

int main(int argc, const char ** argv) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mix(arr, 10);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}