// Mongan, John (2012-11-14). Programming Interviews Exposed: Secrets to Landing Your Next Job (Kindle Location 2583). Wiley. Kindle Edition. 
// Remove Specified Characters
// PROBLEM Write an efficient function that deletes characters from an ASCII string.

#include <iostream>
using namespace std;

void remove_chars(char * str, const char * remove) {
    bool rem_table[128];
    for (int i = 0; i < 128; ++i) {
        rem_table[i] = false;
    }

    const char * rem_ptr = remove;
    while (rem_ptr[0] != '\0') {
        rem_table[rem_ptr[0]] = true;
        rem_ptr++;
    }

    const char * str_ptr = str;
    char * ret_ptr = str;
    while (str_ptr[0] != '\0') {
        if (!rem_table[str_ptr[0]]) {
            ret_ptr[0] = str_ptr[0];
            ret_ptr++;
        }
        str_ptr++;
    }
    ret_ptr[0] = '\0';
}

int main(int argc, const char ** argv) {
    char ret[128] = "Battle of the Vowels: Hawaii vs. Gronzy";
    remove_chars(ret, "aeiou");
    cout << ret << endl;
    return 0;
}