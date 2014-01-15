#include <iostream>
#include <cassert>
using namespace std;

// bonus
bool check_valid_parentheses(const char * str) {
    int n = 0;
    while (str[0] != '\0') {
        if (str[0] == '(') {
            n++;
        }
        else if (str[0] == ')') {
            n--;
        }
        str++;
    }
    return n == 0;
}

// print all valid parentheses
void print_internal(int nl, int nr, char * str, int i) {
    if (nr == 0) {
        assert(check_valid_parentheses(str));
        cout << str << endl;
    }
    if (nl != 0) {
        str[i] = '(';
        print_internal(nl - 1, nr, str, i + 1);
    }
    if (nl < nr) {
        str[i] = ')';
        print_internal(nl, nr - 1, str, i + 1);
    }
}

void print_parentheses(int n) {
    char * str = new char[2 * n + 1];
    str[2 * n] = '\0';
    print_internal(n, n, str, 0);
    delete[] str;
}

int main(int argc, const char ** argv) {
    print_parentheses(3);
    return 0;
}