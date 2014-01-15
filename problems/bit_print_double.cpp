#include <iostream>
using namespace std;

// 0 <= val <= 1
void print_double(double val) {
    if (val == 1.0) {
        cout << "1" << endl;
        return;
    }
    if (val == 0.0) {
        cout << "0" << endl;
        return;
    }
    double bit = 0.5;
    char ret[33];
    bool found = false;
    for (int i = 0; i < 32; ++i) {
        ret[i] = (val >= bit) ? '1' : '0';
        if (val >= bit) {
            val -= bit;
        }
        if (val == 0) {
            ret[i+1] = '\0';
            found = true;
            break;
        }
        bit *= 0.5;
    }
    if (!found) {
        cout << "ERROR" << endl;
    }
    else {
        cout << "0." << ret << endl;
    }
}

int main(int argc, const char ** argv) {
    print_double(0.875);
    print_double(0.5 + 0.125 + 0.125 * 0.25);
    print_double(0.01);
    return 0;
}