#include <iostream>
using namespace std;

// i < j
int insert(int m, int n, int i, int j) {
    // something like this: 0000111100
    int clear = 1;
    for (int k = 0; k < j - i; ++k) {
        clear = clear << 1;
        clear += 1;
    }
    for (int k = 0; k < i; ++k) {
        clear = clear << 1;
    }
    // 1111000011
    clear = ~clear;
    m = m & clear;
    n = n << i;
    return m | n;
}

int main(int argc, const char ** argv) {
    int ret = insert(0x8000, 0x0013, 2, 6);
    cout << ret << endl;
    cout << 0x804C << endl;
    return 0;
}