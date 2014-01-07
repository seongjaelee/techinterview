// find sum of all nodes except leaf
// https://github.com/techpanja/interviewproblems/blob/master/src/trees/treeproblems/FindSumOfAllNodesExceptLeaf.java

struct node {
    node * l;
    node * r;
    int item;
};

int sum_tree(node * n) {
    if (!n) {
        return 0;
    }
    if (!n->l && !n->r) {
        return 0;
    }
    return n->item + sum_tree(n->l) + sum_tree(n->r);
}