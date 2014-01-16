// sorted array to a balanced binary search tree
#include <utility>
#include <iostream>
using namespace std;

struct node {
    int item;
    node * l;
    node * r;
};

node * convert(const int * arr, int n) {
    if (n == 0) {
        return NULL;
    }
    if (n == 1) {
        node * ret = new node();
        ret->item = arr[0];
        ret->l = NULL;
        ret->r = NULL;
    }

    int m = n / 2;
    node * ret = new node();
    ret->item = arr[m];
    ret->l = convert(arr, m);
    ret->r = convert(arr + m + 1, n - m - 1);

    return ret;
}

void print(node * n) {
    if (!n) {
        return;
    }
    if (!n->l && !n->r) {
        cout << n->item;
        return;
    }
    cout << n->item;
    cout << "(";
    print(n->l);
    cout << ",";
    print(n->r);
    cout << ")";
}

void clean(node * n) {
    if (!n) {
        return;
    }
    clean(n->l);
    clean(n->r);
    delete n;
}

int main(int argc, const char ** argv) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i <= n; ++i) {
        node * r = convert(arr, i);
        print(r);
        cout << endl;
        clean(r);
    }
    // we need to delete nodes.
    return 0;
}