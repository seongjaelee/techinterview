// Finds common starting string for a list of strings. For e.g. aab and aaade have aa in common.
// https://github.com/techpanja/interviewproblems/blob/master/src/strings/findcommonprefix/CommonPrefix.java
#include <iostream>
using namespace std;

void find_common_prefix(const char * a, const char * b, char * ret) {
    while (a[0] != '\0' && b[0] != '\0' && a[0] == b[0]) {
        ret[0] = a[0];
        a++;
        b++;
        ret++;
    }
    ret[0] = '\0';
}

int main(int argc, const char ** argv) {
    const char * a = "abcde";
    const char * b = "abcdfe";
    char ret[128];

    find_common_prefix(a, b, ret);
    cout << ret << endl;

    return 0;
}