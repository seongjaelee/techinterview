#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

struct Node {
    int key;
    int h;
    Node * l;
    Node * r;
};

class AvlTree {
public:
    AvlTree();
    ~AvlTree();
    void Insert(int key);
    void Delete(int key);
    void Print() const;
private:
    Node * FindInternal(int key) const;
    Node * InsertInternal(Node * node, int key);
    Node * DeleteInternal(Node * node, int key);
    Node * RotateLeft(Node * node);
    Node * RotateRight(Node * node);
    Node * Balance(Node * node);
    void UpdateHeight(Node * node);
    void DeleteAll(Node * node);
private:
    Node * m_root;
};

AvlTree::AvlTree() {
    m_root = NULL;
}

AvlTree::~AvlTree() {
    DeleteAll(m_root);
}

void AvlTree::DeleteAll(Node * node) {
    if (!node) {
        return;
    }
    DeleteAll(node->l);
    DeleteAll(node->r);
    delete node;
}

void AvlTree::Insert(int key) {
    m_root = InsertInternal(m_root, key);
}

void AvlTree::Delete(int key) {
    m_root = DeleteInternal(m_root, key);
}

void AvlTree::Print() const {
    if (!m_root) {
        return;
    }

    int l = 1;
    for (int i = 0; i < m_root->h - 1; ++i) {
        l *= 2;
    }

    std::queue<Node *> queue;
    queue.push(m_root);
    while (true) {
        std::queue<Node *> next_queue;
        while (!queue.empty()) {
            Node * node = queue.front();
            queue.pop();
            for (int i = 0; i < l - 1; ++i) {
                std::cout << " ";
            }
            if (node) {
                std::cout << node->key;
                next_queue.push(node->l);
                next_queue.push(node->r);
            }
            else {
                std::cout << " ";
                next_queue.push(NULL);
                next_queue.push(NULL);
            }
            for (int i = 0; i < l; ++i) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        queue = next_queue;
        if (l == 0) {
            break;
        }
        l /= 2;
    }
}

Node * AvlTree::RotateRight(Node * node) {
    Node * x = node->l;
    Node * y = node;
    Node * B = x->r;

    x->r = y;
    y->l = B;

    UpdateHeight(y);
    UpdateHeight(x);

    return x;
}

Node * AvlTree::RotateLeft(Node * node) {
    Node * x = node;
    Node * y = node->r;
    Node * B = y->l;

    x->r = B;
    y->l = x;

    UpdateHeight(x);
    UpdateHeight(y);

    return y;
}

Node * AvlTree::FindInternal(int key) const {
    Node * node = m_root;
    while (node && node->key != key) {
        if (key < node->key) {
            node = node->l;
        }
        else {
            node = node->r;
        }
    }
    return node;
}

void AvlTree::UpdateHeight(Node * node) {
    int lh = node->l ? node->l->h : 0;
    int rh = node->r ? node->r->h : 0;
    node->h = std::max(lh, rh) + 1;    
}

Node * AvlTree::Balance(Node * node) {
    int lh = node->l ? node->l->h : 0;
    int rh = node->r ? node->r->h : 0;
    if (lh == rh + 2) {
        int llh = node->l->l ? node->l->l->h : 0;
        int lrh = node->l->r ? node->l->r->h : 0;
        if (llh > lrh) {
            return RotateRight(node);
        }
        else {
            node->l = RotateLeft(node->l);
            return RotateRight(node);
        }
    }
    if (lh == rh - 2) {
        int rlh = node->r->l ? node->r->l->h : 0;
        int rrh = node->r->r ? node->r->r->h : 0;
        if (rrh > rlh) {
            return RotateLeft(node);
        }
        else {
            node->r = RotateRight(node->r);
            return RotateLeft(node);
        }
    }
    return node;
}

Node * AvlTree::InsertInternal(Node * node, int key) {
    if (node == NULL) {
        node = new Node();
        node->key = key;
        node->l = NULL;
        node->r = NULL;
        node->h = 1;
        return node;
    }

    if (key < node->key) {
        node->l = InsertInternal(node->l, key);
    }
    else {
        node->r = InsertInternal(node->r, key);
    }

    UpdateHeight(node);

    node = Balance(node);

    return node;
}

Node * AvlTree::DeleteInternal(Node * node, int key) {
    if (node->key != key) {
        if (key < node->key) {
            node->l = DeleteInternal(node->l, key);
        }
        else {
            node->r = DeleteInternal(node->r, key);
        }
    }
    else {
        if (!node->l && !node->r) {
            delete node;
            return NULL;
        }
        else if (!node->l || !node->r) {
            Node * child = node->l ? node->l : node->r;
            delete node;
            return child;
        }
        else {
            // next node in in-order traversal
            Node * next = node->r;
            while (next->l) {
                next = next->l;
            }

            // swap next node and current node
            node->key = next->key;
            node->r = DeleteInternal(node->r, next->key);
        }
    }

    UpdateHeight(node);

    node = Balance(node);

    return node;
}

int main() {
    AvlTree tree = AvlTree();
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(2);
    tree.Print();
    tree.Insert(1);
    tree.Print();
    tree.Insert(7);
    tree.Print();
    tree.Delete(4);
    tree.Print();
    tree.Delete(6);
    tree.Print();
    tree.Delete(7);
    tree.Print();
}