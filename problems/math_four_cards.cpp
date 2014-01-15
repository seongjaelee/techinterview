// you have four numbers.
// with +, -, /, *, and (), can you make a number 24 using all those cards?
// urgh, I don't know how to solve this problem clean.
#include <iostream>
#include <vector>
using namespace std;

void get_combination(int n, int ind, vector<int> & ret) {
    if (n == 1) {
        ret.push_back(0);
        return;
    }
    vector<int> temp_ret;
    get_combination(n - 1, ind / n, temp_ret);
    for (int i = 0; i < n - 1; ++i) {
        if (ind % n == i) {
            ret.push_back(n - 1);
        }
        ret.push_back(temp_ret[i]);
    }
    if (ind % n == n - 1) {
        ret.push_back(n - 1);
    }
}

void get_permutation(int n, int l, int ind, vector<int> & ret) {
    for (int i = 0; i < l; ++i) {
        ret[i] = ind % n;
        ind /= n;
    }
}

bool make_24(int * arr) {
    vector< vector<int> > number_combinations;
    vector< vector<int> > operation_permutations;

    // number combinations
    // 0, 1, 2, 3 combination
    for (int i = 0; i < 24; ++i) {
        vector<int> numbers;
        get_combination(4, i, numbers);
        for (int j = 0; j < 64; ++j) {
            vector<int> operations;
            get_permutation(4, 3, i, operations);

            double r = arr[numbers[0]];
            for (int k = 0; k < 3; ++k) {
                int op = operations[k];
                int b = arr[numbers[k+1]];
                switch (op) {
                case 0: // add
                    r = r + b;
                    break;
                case 1:
                    r = r - b;
                    break;
                case 2:
                    r = r * b;
                    break;
                case 3:
                    r = r / b;
                    break;
                }
            }
            if (r == 24.0 within epsilon) {
                return true;
            }
        }
    }

    // operation combinations
    // 0, 1, 2, 3 permutation

    // 4! number combination, 3**4 operation combinations, 2 kinds of trees
    // 1. (((a, b), c), d)
    // 2. ((a, b), (c, d))

    return true;
}

int main(int argc, const char ** argv) {
    int arr[] = {2, 4, 6, 3};
    make_24(arr);
    return 0;
}