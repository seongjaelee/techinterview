#include <cassert>
#include <stdio.h>
#include <iostream>

class Hash
{
public:
    Hash();
    ~Hash();
    int Find(int key) const;
    void Insert(int key);
    void Delete(int key);
    void Print() const;

    // we should make sure these values don't overlap with key
    static const int NOT_FOUND = -1;

private:
    int GetHash(int key) const;

    // we should make sure these values don't overlap with key
    static const int EMPTY = -1;
    static const int DEFAULT_SIZE = 4;

    struct Node {
        int key;
        Node * next;
    };

private:
    Node ** m_buckets;
    int m_bucket_size;
};

Hash::Hash() {
    m_bucket_size = DEFAULT_SIZE;
    m_buckets = new Node*[m_bucket_size];
    for (int i = 0; i < m_bucket_size; ++i) {
        m_buckets[i] = NULL;
    }
}

Hash::~Hash() {
    for (int i = 0; i < m_bucket_size; ++i) {
        Node * node = m_buckets[i];
        while (node) {
            Node * next = node->next;
            delete node;
            node = next;
        }
    }
    delete[] m_buckets;
}

int Hash::GetHash(int key) const {
    return key % DEFAULT_SIZE;
}

void Hash::Insert(int key) {
    int index = GetHash(key);
    Node * node = new Node();
    node->key = key;
    node->next = m_buckets[index];
    m_buckets[index] = node;
}

int Hash::Find(int key) const {
    int index = GetHash(key);
    Node * node = m_buckets[index];
    while (node != NULL && node->key != key) {
        node = node->next;
    }
    if (node == NULL) {
        return NOT_FOUND;
    }
    return index; // yes, this is sorta silly.
}

void Hash::Delete(int key) {
    int index = GetHash(key);

    Node * prev = NULL;
    Node * curr = m_buckets[index];
    while (curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    assert(curr);
    if (prev) {
        prev->next = curr->next;
    }
    if (curr == m_buckets[index]) {
        m_buckets[index] = curr->next;
    }
    if (curr) {
        delete curr;
    }
}

void Hash::Print() const {
    for (int i = 0; i < m_bucket_size; ++i) {
        Node * node = m_buckets[i];
        printf("\t%2d : ", i);
        while (node) {
            printf("%2d ", node->key);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    std::cout << "init" << std::endl;
    Hash hash = Hash();
    hash.Print();

    std::cout << "insert" << std::endl;
    hash.Insert(13);
    hash.Insert(14);
    hash.Insert(21);
    hash.Insert(29);
    hash.Print();

    std::cout << "delete" << std::endl;
    hash.Delete(14);
    hash.Delete(13);
    hash.Print();

    std::cout << "find" << std::endl;
    hash.Find(21);
    hash.Find(29);

    std::cout << "insert more" << std::endl;
    hash.Insert(1);
    hash.Insert(2);
    hash.Insert(3);
    hash.Print();

    return 0;
}