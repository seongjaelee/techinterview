#include <iostream>
using namespace std;

// Q1. it takes O(log(dividend))

// return m such that 2^m <= n < 2^(m+1).
int get_highest_digit(int n) {
    int m = 0;
    int x = 1;
    while (2 * x < n && m < 31) {
        x *= 2;
        m++;
    }
    return m;
}

// we suppose the numbers are greater than zero.
int divide(int divisor, int dividend) {
    if (divisor == 0) {
        throw -1; // undefined
    }
    if (dividend == 0) {
        return 0;
    }

    int sign = (divisor * dividend < 0) ? -1 : 1;
    divisor = abs(divisor);
    dividend = abs(dividend);

    if (dividend < divisor) {
        return 0;
    }

    int i = get_highest_digit(dividend) - get_highest_digit(divisor) + 1;
    int d = 1 << i;
    int ret = 0;
    while (d >= 1) {
        if (dividend >= (ret + d) * divisor) {
            ret += d;
        }
        d /= 2;
    }
    return sign * ret;
}

// Q2. sorting takes O(nlogn). I'll use quicksort, so it will take

bool check(int * arr, int n) {
    // suppose arr is a sorted array
    int i = 0;
    int j = n-1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == n) {
            return true;
        }
        else if (sum > n) {
            j--;
        }
        else if (sum < n) {
            i++;
        }
    }
    return false;
}

int main(int argc, const char ** argv) {
    cout << divide(3, 100) << endl;
    cout << divide(3, 99) << endl;
    cout << divide(3, 98) << endl;
    cout << divide(3, 3) << endl;
    cout << divide(3, 2) << endl;
    return 0;
}