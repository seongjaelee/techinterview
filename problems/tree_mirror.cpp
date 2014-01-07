#include <iostream>
using namespace std;

struct node {
    node * l;
    node * r;
};

void swap(node *& a, node *& b) {
    node * t = a;
    a = b;
    b = t;
}

void mirror_tree(node * to_mirror) {
    if (!to_mirror) {
        return;
    }

    node * ret = new node();
    swap(to_mirror->l, to_mirror->r);
    mirror_tree(to_mirror->l);
    mirror_tree(to_mirror->r);
}

int main(int argc, const char ** argv) {
    int parents[] = {-1, 0, 0, 1, 3, 3, 1, 6, 7, 7, 2, 10, 11, 12, 10, 14, 15, 16, 16};
    int n = sizeof(parents) / sizeof(int);

    node * nodes = new node[n];
    for (int i = 0; i < n; ++i) {
        nodes[i].l = NULL;
        nodes[i].r = NULL;
    }
    for (int i = 0; i < n; ++i) {
        if (parents[i] == -1) {
            continue;
        }
        if (!nodes[parents[i]].l) {
            nodes[parents[i]].l = &nodes[i];
        }
        else {
            nodes[parents[i]].r = &nodes[i];
        }
    }

    mirror_tree(&nodes[0]);

    delete[] nodes;

    return 0;
}