struct Node {
    Node * l_node;
    Node * r_node;
    int item;
};

Node * breadthFirstSearch(Node * root, int item) {
    std::queue<Node *> queue;
    queue.enqueue(root);
    while (!queue.empty()) {
        Node * node = queue.dequeue();
        if (node->item == item) {
            return node;
        }
        if (node->l_node) {
            queue.enqueue(node->l_node);
        }
        if (node->r_node) {
            queue.enqueue(node->r_node);
        }
    }
}

Node * depthFirstSearch(Node * node, int item) {
    Node * ret;

    if (node->l_node) {
        ret = depthFirstSearch(node->l_node, item);
        if (ret) {
            return ret;
        }
    }
    if (node->item == item) {
        return node;
    }
    if (node->r_node) {
        ret = depthFirstSearch(node->r_node, item);
        if (ret) {
            return ret;
        }
    }
    return NULL;
}