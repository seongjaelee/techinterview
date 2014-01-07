// http://crackprogramming.blogspot.com/2012/10/implement-atof.html
#include <iostream>

double atof(const char * str) {
    bool negative = false;
    if (str[0] == '+') {
        str++;
    }
    else if (str[0] == '-') {
        negative = true;
        str++;
    }

    double ret = 0.0;
    while (str[0] != '.') {
        ret *= 10;
        ret += int(str[0] - '0');
        str++;
        if (str[0] == '\0') {
            return negative ? -ret : ret;
        }
    }

    str++;
  
    double decimal = 1.0;
    while (str[0] != '\0') {
        decimal /= 10;
        ret += decimal * int(str[0] - '0');
        str++;
    }

    return negative ? -ret : ret;
}

int main(int argc, const char ** argv) {
    const char * str = "-0230.02";
    // const char * str = "-.02";
    std::cout << atof(str) << std::endl;
    return 0;
}