/*
Diameter of a Tree is defined as the number of nodes on the longest path between two leaves in the tree.
http://crackinterviewtoday.wordpress.com/2010/03/11/diameter-of-a-binary-tree/
*/

#include <iostream>
using namespace std;

struct node {
    node * l;
    node * r;
};

void get_diameter(node * n, int & diameter, int & depth) {
    depth = 0;
    diameter = 0;

    if (!n->l && !n->r) {
        return;
    }

    int l_diameter = -1;
    int l_depth = -1;
    if (n->l) {
        get_diameter(n->l, l_diameter, l_depth);
    }

    int r_diameter = -1;
    int r_depth = -1;
    if (n->r) {
        get_diameter(n->r, r_diameter, r_depth);
    }

    if (l_depth == -1 || r_depth == -1) {
        diameter = max(l_diameter, r_diameter);
        depth = max(l_depth, r_depth) + 1;
        return;
    }

    diameter = l_depth + r_depth + 2;
    diameter = max(diameter, l_diameter);
    diameter = max(diameter, r_diameter);
    depth = max(l_depth, r_depth) + 1;
}

int main(int argc, const char ** argv) {
    // create a tree
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

    int diameter = 0;
    int depth = 0;
    for (int i = 0; i < n; ++i) {
        get_diameter(&nodes[i], diameter, depth);
        cout << i << ": " << diameter << endl;
    }

    // delete the tree
    delete[] nodes;

    return 0;
}