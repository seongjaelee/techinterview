// pair<int, int>
// find the length of the longest sequences such that arr[i].first <= arr[j].first && arr[i].second <= arr[j].second for all i < j.

#include <iostream>
#include <utility>
using namespace std;

void swap(pair<int, int> & a, pair<int, int> & b) {
    pair<int, int> t = a;
    a = b;
    b = t;
}

// quicksort
void sort(pair<int, int> * arr, int n) {
    if (n <= 1) {
        return;
    }
    int p = arr[0].first;
    int i = 1;
    int j = n - 1;
    while (i < j) {
        if (arr[i].first <= p) {
            i++;
        }
        else {
            swap(arr[i].first, arr[j].first);
            j--;
        }
    }
    if (arr[i].first > p) {
        i--;
    }
    swap(arr[0].first, arr[i].first);
    sort(arr, i);
    sort(arr + i + 1, n - i - 1);
}

int get_length_of_longest_double_sorted(pair<int, int> * arr, int n) {
    sort(arr, n);

    int * num = new int[n];
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        num[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[j].second <= arr[i].second) {
                num[i] = max(num[i], num[j] + 1);
            }
        }
        ret = max(ret, num[i]);
    }
    delete[] num;

    return ret;
}

int main(int argc, const char ** argv) {
    pair<int, int> arr[] = {pair<int, int>(65, 100), pair<int, int>(70, 150), pair<int, int>(56, 90), pair<int, int>(75, 190), pair<int, int>(60, 95), pair<int, int>(68, 110)};
    int n = sizeof(arr) / sizeof(pair<int, int>);
    int r = get_length_of_longest_double_sorted(arr, n);
    cout << r << endl;
    return 0;
}