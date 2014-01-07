#include <iostream>
#include <cassert>

using namespace std;

// reverse the words of a string (example i/p: sunny in seattle o/p: seattle in sunny)
void reverse(char * str) {
    char * str_copy = str;
    while (*str_copy != '\0') {
        str_copy++;
    }
    const int len = str_copy - str;

    char * buffer = new char[len];

    int buffer_index = 0;
    int last = len;
    for (int i = len-1; i >= 0; i--) {
        if (str[i] == ' ') {
            int init = i + 1;
            for (int j = init; j < last; j++) {
                buffer[buffer_index++] = str[j];
            }
            // assume there is only one space between words
            buffer[buffer_index++] = ' ';
            last = init - 1;
        }
    }
    for (int j = 0; j < last; j++) {
        buffer[buffer_index++] = str[j];
    }
    for (int i = 0; i < len; ++i) {
        str[i] = buffer[i];
    }
    delete[] buffer;
}

int main() {
    char str[256] = "sunny in seattle";
    reverse(str);
    std::cout << str << std::endl;
    return 0;
}