// sort a linked list
struct node {
    int item;
    node * next;
};

void sort(node * head, node *& ret_head, node *& ret_tail) {
    node * p = head;

    if (!p) {
        ret_head = NULL;
        ret_tail = NULL;
        return;
    }

    node * l = NULL;
    node * r = NULL;
    node * n = head->next;
    while (n) {
        if (p->item <= n->item) {
            n->next = l;
            l = n;
        }
        else {
            n->next = r;
            r = n;
        }
        n = n->next;
    }

    p->next = NULL;
    ret_head = p;
    ret_tail = p;
    if (l) {
        node * a, b;
        sort(l, a, b);
        ret_head = a;
        b->next = p;
    }
    if (r) {
        node * a, b;
        sort(r, a, b);
        p->next = a;
        ret_tail = b;
    }
}