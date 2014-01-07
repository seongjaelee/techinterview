#include <iostream>
using namespace std;

void swap(int & a, int & b) {
    int t = a;
    a = b;
    b = t;
}

void print(const int * arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

void heapify(int * arr, int i, int n) {
    int l = i * 2 + 1;
    int r = l + 1;
    int maxarg = i;
    if (l < n && arr[maxarg] < arr[l]) {
        maxarg = l;
    }
    if (r < n && arr[maxarg] < arr[r]) {
        maxarg = r;
    }
    if (i != maxarg) {
        swap(arr[i], arr[maxarg]);
        heapify(arr, maxarg, n);
    }
}

void heapsort(int * arr, int size) {
    for (int i = size / 2; i >= 0; --i) {
        heapify(arr, i, size);
    }
    for (int i = size - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

void quicksort(int * arr, int size) {
    if (size <= 1) {
        return;
    }

    int pivot = arr[0];
    int i = 1;
    int j = size - 1;
    while (i < j) {
        if (arr[i] <= pivot) {
            i++;
        }
        else {
            swap(arr[i], arr[j]);
            j--;
        }
    }

    if (arr[i] > pivot) {
        i--;
    }
    swap(arr[0], arr[i]);

    quicksort(arr, i);
    quicksort(arr + i + 1, size - i - 1);
}

void mergesort(int * arr, int * buf, int size) {
    if (size <= 1) {
        return;
    }

    int n = size / 2;
    mergesort(arr, buf, n);
    mergesort(arr + n, buf, size - n);

    // merge
    int i = 0;
    int j = n;
    int k = 0;
    while (i < n && j < size) {
        if (arr[i] < arr[j]) {
            buf[k++] = arr[i++];
        }
        else {
            buf[k++] = arr[j++];
        }
    }
    while (i < n) {
        buf[k++] = arr[i++];
    }
    while (j < size) {
        buf[k++] = arr[j++];
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = buf[i];
    }
}

int main(int argc, const char ** argv) {
    int arr[] = {3,2,1,7,4,8,6,10,9,5};
    int n = sizeof(arr)/sizeof(int);
    int buf[n];

    print(arr, n);
 
    heapsort(arr, n);
    // quicksort(arr, n);
    // mergesort(arr, buf, n);
    print(arr, n);
}