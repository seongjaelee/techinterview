// For e.g. 2.1 and 2.2 should return 2.2. e.g. 3.2 and 3.2.1 should return 3.2.1
// https://github.com/techpanja/interviewproblems/blob/master/src/strings/findlatestversion/FindLatestVersion.java

#include <iostream>
using namespace std;

// returns false if a > b
bool is_latest_version(const char * a, const char * b) {
    char buf_a[128];
    int i = 0;
    while (a[i] != '.' && a[i] != '\0') {
        buf_a[i] = a[i];
        i++;
    }
    buf_a[i] = '\0';

    char buf_b[128];
    int j = 0;
    while (b[j] != '.' && b[j] != '\0') {
        buf_b[j] = b[j];
        j++;
    }
    buf_b[j] = '\0';

    int aa = (i != 0) ? atoi(buf_a) : 0;
    int bb = (j != 0) ? atoi(buf_b) : 0;

    if (aa > bb) {
        return true;
    }
    if (aa < bb) {
        return false;
    }
    if (i == 0 && j == 0) {
        return true;
    }
    return is_latest_version(a+i+1, b+j+1);
}

int main(int argc, const char ** argv) {
    cout << is_latest_version("2.1", "2.2") << endl;
    cout << is_latest_version("3.2", "3.2.1") << endl;
    cout << is_latest_version("2.2", "2.1") << endl;
    cout << is_latest_version("3.2.1", "3.2") << endl;
    cout << is_latest_version("3.2.0", "3.2") << endl;
    cout << is_latest_version("3.2", "3.2.0") << endl;
    cout << is_latest_version("3.2", "3.2.0.1") << endl;
    cout << is_latest_version("3.2.0.1", "3.2") << endl;
    return 0;
}