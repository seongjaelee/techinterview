#include <iostream>

// this is O(nm) algorithm.
const char * mystrstr(const char * haystack, const char * needle) {
    int n = strlen(haystack);
    int m = strlen(needle);
    for (int i = 0; i < n; ++i) {
        bool found = true;
        for (int j = 0; j < m; ++j) {
            if (haystack[i+j] != needle[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            std::cout << i << std::endl;
            return haystack + i;
        }
    }
    return haystack + n;
}

int main() {
    const char * haystack = "hello world my name is soeng jae lee world!";
    const char * needle = "world!";
    std::cout << mystrstr(haystack, needle) << std::endl;
}