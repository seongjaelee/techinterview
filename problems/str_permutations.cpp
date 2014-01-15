// write a method to compute all permutations of a string
#include <map>
#include <iostream>
using namespace std;

/*
map<char, int> bins;

1. convert string to bins
2. then i'll use a recursive algorithm to put one character fron the bins and attach it to the string
*/

// O(nc) if n is the strlen(str), and c is the number of characters
void print_permutation_internal(map<char, int> & bins, char * str, int i, int n) {
    for (map<char, int>::iterator it = bins.begin(); it != bins.end(); it++) {
        if ((*it).second == 0) {
            // do nothing
        }
        else {
            char c = (*it).first;
            str[i] = c;
            if (i == n - 1) {
                cout << str << endl;
                return;
            }

            bins[c]--;
            bool erase = (bins[c] == 0);
            if (erase) {
                bins.erase(c);
            }
            print_permutation_internal(bins, str, i + 1, n);
            if (erase) {
                bins[c] = 0;
            }
            bins[c]++;
        }
    }
}

void print_permutation(const char * str) {
    map<char, int> bins;
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        if (bins.find(str[i]) == bins.end()) {
            bins[str[i]] = 0;
        }
        bins[str[i]]++;
    }

    char * str_copy = new char[n + 1];
    str_copy[n] = '\0';
    print_permutation_internal(bins, str_copy, 0, n);
    delete[] str_copy;
}

int main(int argc, const char ** argv) {
    print_permutation("aabb");
    return 0;
}