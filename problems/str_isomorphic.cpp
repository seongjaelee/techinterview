 /*
Given two (dictionary) words as Strings, determine if they are isomorphic. Two words are called isomorphic if the letters in one word can be remapped to get the second word. Remapping a letter means replacing all occurrences of it with another letter while the ordering of the letters remains unchanged. No two letters may map to the same letter, but a letter may map to itself.
https://github.com/techpanja/interviewproblems/blob/master/src/strings/isomorphicstrings/Isomorphic.java
*/
#include <map>
#include <cassert>
using namespace std;

bool is_isomorphic(const char * a, const char * b) {
    if (strlen(a) != strlen(b)) {
        return false;
    }
    
    map<char, char> str_map;
    map<char, char> str_inv_map;
    while (a[0] != '\0') {
        if (str_map.find(a[0]) == str_map.end()) {
            if (str_inv_map.find(b[0]) != str_inv_map.end()) {
                return false;
            }
            str_map[a[0]] = b[0];
            str_inv_map[b[0]] = a[0];
        }
        else {
            if (b[0] != str_map[a[0]]) {
                return false;
            }
        }
        a++;
        b++;
    }
    return true;
}

int main(int argc, const char ** argv) {
    assert(is_isomorphic("foo", "app"));
    assert(!is_isomorphic("axy", "boo"));
    assert(is_isomorphic("turtle", "tletur"));
    assert(is_isomorphic("ab", "ca"));
    assert(!is_isomorphic("ab", "cad"));
    return 0;
}