#include <iostream>
#include <limits>
using namespace std;

void find_max_sub_subarray(const int * arr, int size, int & init, int & last) {
    init = 0;
    last = 1;

    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    int init_temp = 0;
    for (int i = 0; i < size; ++i) {
        if (max_ending_here < 0) {
            max_ending_here = arr[i];
            init_temp = i;
        }
        else {
            max_ending_here += arr[i];
        }

        if (max_ending_here >= max_so_far) {
            max_so_far = max_ending_here;
            init = init_temp;
            last = i + 1;
        }
    }
}

// // it takes O(n^2). can we make it faster?
// // yes! http://en.wikipedia.org/wiki/Kadane%27s_Algorithm
// void find_max_sub_subarray(const int * arr, int size, int & init, int & last) {
//     int * buf = new int[size + 1];
//     buf[0] = 0;
//     for (int i = 0; i < size; ++i) {
//         buf[i + 1] = buf[i] + arr[i];
//     }

//     int maxval = numeric_limits<int>::min();
//     init = 0;
//     last = size;
//     for (int i = 0; i < size; ++i) {
//         for (int j = i+1; j < size + 1; ++j) {
//             if (maxval < buf[j] - buf[i]) {
//                 maxval = buf[j] - buf[i];
//                 init = i;
//                 last = j;
//             }
//         }
//     }
// }

int main(int argc, const char ** argv) {
    int arr[] = {-1, 3, 4, 3, 10, -30, 30, -2, 4};
    int n = sizeof(arr) / sizeof(int);
    int init, last;
    find_max_sub_subarray(arr, n, init, last);
    cout << init << ", " << last << endl;
    for (int i = init; i < last; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}