#include <iostream>
using namespace std;

unsigned sqrt(unsigned n) { 
    if (n == 0) {
        return 0;
    }
    
    int highest_bit = 15;
    unsigned m = 1 << highest_bit;
    while (m * m > n) {
        highest_bit--;
        m = 1 << highest_bit;
    }

    // we get m such that m^2 < n < 4m^2.
    // wait a sec. what about the buffer overflow?
    for (int j = highest_bit - 1; j >=0; j--) {
        unsigned t = m + (1 << j);
        // if (t * t < 0) {
        //     // buffer overflow
        //     cout << t << ", " << t*t << endl;
        //     continue;
        // }
        if (t * t == n) {
            return t;
        }
        if (t * t < n) {
            m = t;
        }
    }
    return 0;
}

int main(int argc, const char ** argv) {
    unsigned t = (1 << 15) + 123;
    cout << t * t << endl;
    cout << sqrt(t * t) << endl;
    cout << sqrt(0x7fffffff) << endl;
}