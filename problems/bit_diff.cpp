#include <iostream>
using namespace std;

int bit_diff(int a, int b) {
    int r = a ^ b;
    int ret = 0;
    while (r != 0) {
        ret += r & 1;
        r = r >> 1;
    }
    return ret;
}

draw_horizontal_line(byte[] screen, int width, int x1, int x2, int y) {
    int i = width / 8 * y;
    // [x1 t1, t2 x2]
    int t1 = x1 / 8;
    int t2 = x2 / 8;
    if (t1 == t2) {
        // x1 ~ x2
        screen[i + t1] &= (0xFF >> (x1 - t1 * 8)) ^ (0xFF >> (x2 - t1 * 8));
    }
    else {
        // x1 ~ t1
        // x1 ~ t1 * 8 = 1 ~ 7
        // when this is 1, 
        screen[i + t1] &= (byte) (0xFF >> x1 - t1 * 8);
        // t1 ~ t2
        for (int j = t1 + 1; j < t2; j++) {
            screen[i + j] &= (byte) 0xFF;
        }
        // t2 ~ x2
        // x2 - t2 * 8 = 1 ~ 7
        // when this is 1, then 0xFF << 7 = 1000000;
        // when this is 7, then 0xFF << 1 = 1111110;
        screen[i + t2] &= (byte) ~(0xFF >> x2 - t2 * 8 + 1);
    }
}

int main(int argc, const char ** argv) {
    // 00111010
    // 00101111
    cout << bit_diff(0x003a, 0x002f) << endl;
    return 0;
}
