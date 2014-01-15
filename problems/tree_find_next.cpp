struct node {
    node * p;
    node * l;
    node * r;
};

// in-order traversal
node * find_next(node * n) {
    if (!n->p && !n->l) {
        return NULL;
    }

    if (n->r) {
        node * t = n->r;
        while (t->l) {
            t = t->l;
        }
        return t;
    }
    else {
        node * c = n;
        node * p = n->p;
        while (p && p->r == c) {
            c = p;
            p = c->p;
        }
        return c;
    }
}