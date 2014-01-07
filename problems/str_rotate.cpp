#include <iostream>
#include <string>

// http://crackprogramming.blogspot.com/2012/10/rotate-given-string-by-position.html
void swap(char & a, char & b) {
    char c = b;
    b = a;
    a = c;
}

void reverse_str(char * str, int n) {
    for (int i = 0; i < n/2; ++i) {
        swap(str[i], str[n-i-1]);
    }
}

void rotate_str(char * str, int r) {
    int n = strlen(str);
    if (r < 0) {
        r += (-r / n + 1) * n;
    }
    r = r % n;
    reverse_str(str, n);
    reverse_str(str, r);
    reverse_str(str+r, n-r);
}

int main() {
    char str[255] = "hello world my name is seong jae lee";
    rotate_str(str, 10);
    std::cout << str << std::endl;
    return 0;
}