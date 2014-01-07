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

    static const int NOT_FOUND = -1;

private:
    void Resize();
    int GetHash(int key) const;

private:
    int * m_buckets;
    int m_bucket_size;
    int m_size;

    // we should make sure these values don't overlap with key
    static const int EMPTY = -1;
    static const int DELETED = -2;
    static const int DEFAULT_SIZE = 8;
};

Hash::Hash() {
    m_buckets = new int[DEFAULT_SIZE];
    m_bucket_size = DEFAULT_SIZE;
    m_size = 0;
    for (int i = 0; i < m_bucket_size; ++i) {
        m_buckets[i] = EMPTY;
    }
}

Hash::~Hash() {
    delete[] m_buckets;
}

int Hash::GetHash(int key) const {
    return key % m_bucket_size;
}

int Hash::Find(int key) const {
    int index = GetHash(key);
    int value = m_buckets[index];
    while (value != EMPTY && value != key) {
        index = (index + 1) % m_bucket_size;
        value = m_buckets[index];
    }
    if (value == EMPTY) {
        return NOT_FOUND; // not found
    }
    return index;
}

void Hash::Insert(int key) {
    int index = GetHash(key);

    // linear probing
    while (m_buckets[index] != EMPTY || m_buckets[index] == DELETED) {
        index = (index + 1) % m_bucket_size;
    }

    m_buckets[index] = key;
    m_size += 1;

    // if load factor is greater than 3/4, rehash
    if (m_size > m_bucket_size * 3 / 4) {
        Resize();
    }
}

void Hash::Delete(int key) {
    int index = GetHash(key);
    assert(index != NOT_FOUND);
    m_buckets[index] = DELETED;
}

void Hash::Resize() {
    int old_bucket_size = m_bucket_size;
    int * old_buckets = m_buckets;
    m_bucket_size *= 2;
    m_buckets = new int[m_bucket_size];
    for (int i = 0; i < m_bucket_size; ++i) {
        m_buckets[i] = EMPTY;
    }

    // rehash
    for (int i = 0; i < old_bucket_size; ++i) {
        int key = old_buckets[i];
        if (key == DELETED) {
            m_size--;
        }
        if (key == EMPTY || key == DELETED) {
            continue;
        }
        Insert(key);
    }

    delete[] old_buckets;
}

void Hash::Print() const {
    printf("\t");
    for (int i = 0; i < m_bucket_size; ++i) {
        printf("%2d ", m_buckets[i]);
    }
    printf("\n");
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
    hash.Print();

    std::cout << "find" << std::endl;
    hash.Find(13);
    hash.Find(14);
    assert(hash.Find(14) == Hash::NOT_FOUND);
    hash.Find(21);
    hash.Find(29);

    std::cout << "insert more to resize" << std::endl;
    hash.Insert(1);
    hash.Insert(2);
    hash.Insert(3);
    hash.Print();

    return 0;
}