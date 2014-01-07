// move all even elements to left. don't use an extra array.
// time O(n), space O(1)

#include <iostream>
using namespace std;

void swap(int & a, int & b) {
    int t = a;
    a = b;
    b = t;
}

void move_even_elems_to_left(int * arr, int size) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        if (arr[i] % 2 == 0) {
            i++;
        }
        else {
            swap(arr[i], arr[j]);
            j--;
        }
    }
}

int main(int argc, const char ** argv) {
    int arr[] = {0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7};
    int size = sizeof(arr) / sizeof(int);
    move_even_elems_to_left(arr, size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}