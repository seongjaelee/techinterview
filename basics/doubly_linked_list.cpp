#include <iostream>
using namespace std;

struct node {
    node * next;
    node * prev;
    int item;
};

class list {
public:
    list();
    virtual ~list();

    void reverse();
    void insert_head(int item);
    void insert_at(int i, int item);
    void remove_at(int i);
    node * at(int i) const;
    bool empty() const;
    void print() const;
    int size() const;

private:
    node * m_head;
    node * m_tail;
    int m_size;
};

list::list()
    : m_head(NULL)
    , m_tail(NULL)
    , m_size(0)
{}

list::~list()
{
    node * n = m_head;
    node * m;
    while (n) {
        m = n->next;
        delete n;
        n = m;
    }
}

void list::remove_at(int i) {
    node * n = this->at(i);
    if (n->prev) {
        n->prev->next = n->next;
    }
    if (n->next) {
        n->next->prev = n->prev;
    }
    if (n == m_head) {
        m_head = n->next;
    }
    if (n == m_tail) {
        m_tail = n->prev;
    }
    m_size--;

    delete n;
}

node * list::at(int i) const {
    node * n = m_head;
    while (i > 0) {
        n = n->next;
        i--;
    }
    return n;
}

int list::size() const {
    return m_size;
}

bool list::empty() const {
    return m_size == 0;
}

void list::insert_head(int item) {
    node * n = new node();
    n->next = m_head;
    n->prev = NULL;
    n->item = item;
    m_head = n;
    m_size++;
}

void list::insert_at(int i, int item) {
    node * next = NULL;
    node * prev = NULL;

    if (i != m_size) {
        next = this->at(i);
    }

    if (next) {
        prev = next->prev;
    }
    else if (i != 0) {
        prev = this->at(i - 1);
    }

    node * curr = new node();
    curr->item = item;
    curr->next = next;
    curr->prev = prev;
    if (prev)
        prev->next = curr;
    if (next)
        next->prev = curr;
    if (i == 0)
        m_head = curr;
    if (i == m_size)
        m_tail = curr;
    m_size++;
}

void list::print() const {
    node * n = m_head;
    while (n) {
        cout << n->item << ", ";
        n = n->next;
    }
    cout << endl;
}

void list::reverse() {
    node * prev_head = m_head;
    node * prev_tail = m_tail;

    node * prev = NULL;
    node * curr = m_head;
    node * next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    m_head = prev_tail;
    m_tail = prev_head;
}

int main(int argc, const char ** argv) {
    list lst;
    lst.insert_at(0, 10);
    lst.insert_at(0, 5);
    lst.insert_at(1, 6);
    lst.print();
    lst.reverse();
    lst.print();
    lst.remove_at(2);
    lst.print();
    return 0;
}