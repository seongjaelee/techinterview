// write a program to sort a stack in ascending order by using only stacks.

#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

void reverse(stack<int> & s, stack<int> & r) {
    assert(r.empty());
    while (!s.empty()) {
        r.push(s.top());
        s.pop();
    }
}

// smallest on the top
// sort of quicksort
void sort(stack<int> & s) {
    if (s.empty()) {
        return;
    }

    int pivot = s.top();
    s.pop();

    // l for equal to or smaller than of the pivot
    // r for equal to or greater than the pivot
    // it takes O(n)
    stack<int> l;
    stack<int> r;
    while (!s.empty()) {
        int v = s.top();
        if (v < pivot) {
            l.push(v);
        }
        else {
            r.push(v);
        }
        s.pop();
    }
    sort(l);
    sort(r);
    assert(s.empty());

    // m for merged
    stack<int> m;
    while (!l.empty()) {
        m.push(l.top());
        l.pop();
    }
    m.push(pivot);
    while (!r.empty()) {
        m.push(r.top());
        r.pop();
    }

    // m; smallest on the bottom
    reverse(m, s);
}

int main(int argc, const char ** argv) {
    int arr[] = {3, 2, 1, 6, 5, 4, 0, 7};
    stack<int> s;
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        s.push(arr[i]);
    }
    sort(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}