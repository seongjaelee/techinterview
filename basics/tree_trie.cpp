#include <iostream>
#include <cassert>
using namespace std;

class Node {
public:
    Node();
    virtual ~Node();
    void insert(const char * str);
    void remove(const char * str);
    bool contain(const char * str) const;
    void print(int indent) const;

private:
    Node * find(char c) const;

private:
    char m_c;
    bool m_marker;
    Node * m_children;
    Node * m_next;
};

Node::Node()
    : m_c('\0'), 
      m_children(NULL), 
      m_next(NULL), 
      m_marker(false) {
    // do nothing
}

Node::~Node() {
    Node * curr = m_children;
    Node * next = NULL;
    while (curr) {
        next = curr->m_next;
        delete curr;
        curr = next;
    }
}

bool Node::contain(const char * str) const {
    if (str[0] == '\0') {
        return m_marker;
    }

    Node * child = find(str[0]);
    return child && child->contain(str + 1);
}

void Node::print(int indent) const {
    if (m_c != '\0') {
        for (int i = 0; i < indent; ++i) {
            cout << " ";
        }
        cout << m_c;
        if (m_marker) {
            cout << "*";
        }
        cout << endl;
    }

    Node * curr = m_children;
    while (curr) {
        curr->print(indent + 1);
        curr = curr->m_next;
    }

    if (indent == 0) {
        cout << endl;
    }
}

void Node::insert(const char * str) {
    if (str[0] == '\0') {
        m_marker = true;
        return;
    }
    Node * child = find(str[0]);
    if (!child) {
        child = new Node();
        child->m_c = str[0];
        child->m_next = m_children;
        m_children = child;
    }
    child->insert(str + 1);
}

void Node::remove(const char * str) {
    if (str[0] == '\0') {
        m_marker = false;
        return;
    }

    Node * curr = m_children;
    Node * prev = NULL;
    while (curr) {
        if (str[0] == curr->m_c) {
            break;
        }
        prev = curr;
        curr = curr->m_next;
    }

    if (!curr) {
        return;
    }

    curr->remove(str + 1);

    if (!curr->m_children && !curr->m_marker) {
        if (prev) {
            prev->m_next = curr->m_next;
        }
        else {
            m_children = curr->m_next;
        }
        delete curr;
    }
}

Node * Node::find(char c) const {
    Node * curr = m_children;
    while (curr) {
        if (c == curr->m_c) {
            return curr;
        }
        curr = curr->m_next;
    }
    return NULL;
}

int main(int argc, const char ** argv) {
    Node node;
    node.insert("cat");
    node.insert("can");
    node.insert("cam");
    node.insert("ban");
    node.insert("ban");
    node.insert("b");
    assert(node.contain("b"));
    assert(!node.contain("ba"));
    assert(node.contain("ban"));
    node.print(0);
    node.remove("cam");
    node.remove("ban");
    node.print(0);
    return 0;
}