#include <iostream>
using namespace std;

template <typename T>
class stack_list {
private:
    struct node {
        T item;
        node * next;
    };
public:
    stack_list() {
        m_head = NULL;
    }
    virtual ~stack_list() {
        node * curr = m_head;
        node * temp;
        while (curr) {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    bool empty() const {
        return !m_head;
    }
    void push(T item) {
        node * curr = new node();
        curr->item = item;
        curr->next = m_head;
        m_head = curr;
    }
    T pop() {
        if (empty()) {
            throw -1;
        }
        T ret = m_head->item;
        m_head = m_head->next;
        return ret;
    }
    void print() const {
        node * curr = m_head;
        while (curr) {
            cout << curr->item << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
private:
    node * m_head;
};

template <typename T>
class stack {
private:
    static const int INIT_SIZE = 8;
public:
    stack() {
        m_size = 0;
        m_capacity = INIT_SIZE;
        m_arr = new T[INIT_SIZE];
    }
    virtual ~stack() {
        delete[] m_arr;
    }
    T pop() {
        if (empty()) {
            throw -1;
        }

        T ret = m_arr[m_size--];

        if (m_size * 2 < m_capacity && m_capacity < INIT_SIZE) {
            m_capacity /= 2;
            T * new_arr = new T[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
        }

        return ret;
    }
    void push(T item) {
        if (m_size == m_capacity) {
            m_capacity *= 2;
            T * new_arr = new T[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
        }

        m_arr[m_size++] = item;
    }
    bool empty() const {
        return m_size == 0;
    }
    void print() const {
        for (int i = 0; i < m_size; ++i) {
            cout << m_arr[i] << ", ";
        }
        cout << endl;
    }
    int size() const {
        return m_size;
    }
    int capacity() const {
        return m_capacity;
    }
private:
    T * m_arr;
    int m_size;
    int m_capacity;
};

int main(int argc, const char ** argv) {
    stack<int> mystack;
    for (int i = 0; i < 100; ++i) {
        mystack.push(i);
    }
    cout << mystack.size() << endl;
    cout << mystack.capacity() << endl;
    for (int i = 0; i < 100; ++i) {
        mystack.pop();
    }
    cout << mystack.size() << endl;
    cout << mystack.capacity() << endl;

    stack_list<int> mystack_list;
    for (int i = 0; i < 20; ++i) {
        mystack_list.push(i);
    }
    mystack_list.print();
    for (int i = 0; i < 10; ++i) {
        mystack_list.pop();
    }
    mystack_list.print();
    return 0;
}