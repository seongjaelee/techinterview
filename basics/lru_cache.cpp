#include <iostream>
#include <map>
using namespace std;

template <typename K, typename T>
class cache {
public:
    cache();
    virtual ~cache();
    T get(K key);
    void put(K key, T data);
    void print() const;
private:
    struct node {
        K key;
        T data;
        node * prev;
        node * next;
    };

    map<K, node *> m_map;
    node * m_head;
    node * m_tail;

    static const int NUM_NODES = 8;
};

template <typename K, typename T>
cache<K, T>::cache() {
    m_head = NULL;
    m_tail = NULL;

    node * curr = NULL;
    node * prev = NULL;
    for (int i = 0; i < NUM_NODES; ++i) {
        curr = new node();
        curr->next = NULL;
        curr->prev = prev;
        if (prev) {
            prev->next = curr;
        }
        else {
            m_head = curr;
        }
        prev = curr;
    }
    m_tail = curr;
}

template <typename K, typename T>
cache<K, T>::~cache() {
    node * curr = NULL;
    node * next = NULL;
    curr = m_head;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename K, typename T>
T cache<K, T>::get(K key) {
    if (m_map.find(key) == m_map.end()) {
        throw -1;
    }
    node * n = m_map[key];
    if (n != m_head) {
        if (n->next) n->next->prev = n->prev;
        if (n->prev) n->prev->next = n->next;
        if (n == m_tail) m_tail = n->next;
        n->next = m_head;
        n->next->prev = n;
        m_head = n;
    }
    return n->data;
}

template <typename K, typename T>
void cache<K, T>::put(K key, T data) {
    if (m_map.find(key) != m_map.end()) {
        get(key);
        m_map[key]->data = data;
    }
    else {
        node * n = m_tail;
        n->prev->next = NULL;
        m_tail = n->prev;

        if (m_map.find(n->key) != m_map.end()) {
            m_map.erase(n->key);
        }

        m_map[key] = n;
        
        n->data = data;
        n->key = key;
        n->prev = NULL;
        n->next = m_head;
        n->next->prev = n;
        m_head = n;
    }
}

template <typename K, typename T>
void cache<K, T>::print() const {
    node * n = m_head;
    while (n) {
        cout << n->key << ", " << n->data << endl;
        n = n->next;
    }
    cout << endl;
}

int main(int argc, const char ** argv) {
    cache<int, int> my_cache;
    my_cache.put(1, 101);
    my_cache.put(2, 101);
    my_cache.put(3, 101);
    my_cache.put(4, 101);
    my_cache.put(1, 102);
    my_cache.print();
    my_cache.put(5, 101);
    my_cache.put(6, 101);
    my_cache.put(7, 101);
    my_cache.put(8, 101);
    my_cache.print();
    my_cache.put(9, 101);
    my_cache.print();
    return 0;
}