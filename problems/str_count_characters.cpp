#include <iostream>
#include <map>

// this is more like about how to use map properly.
void count_chars(const char * arr) {
    int n = strlen(arr);
    std::map<char, int> bins;
    while (*arr != '\0') {
        if (bins.find(*arr) == bins.end()) {
            bins[*arr] = 1;
        }
        else {
            bins[*arr] += 1;
        }
        arr++;
    }

    // http://stackoverflow.com/questions/3865432/does-hash-map-automatically-sort-c
    // The actual reason is the hash_map's bucket_count is 193 and the hash function of int is an identity function, 
    // so any numbers below 193 will appear sorted.
    for(std::map<char, int>::iterator it = bins.begin(); it != bins.end(); it++) {
        std::cout << it->first << ":" << it->second << std::endl;
    }
}

int main() {
    const char * str = "hello world my name is seong jae lee";
    count_chars(str);
    return 0;
}