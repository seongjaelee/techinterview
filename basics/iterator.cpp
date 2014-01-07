#include <iostream>

using namespace std;

template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool has_next() = 0;
    virtual T next() = 0;
};

template <typename T>
class ArrayIterator : public Iterator<T> {
public:
    ArrayIterator(const T * arr, int size): m_arr(arr), m_size(size), m_index(0) {}
    virtual ~ArrayIterator() {}
    virtual bool has_next() { return m_index < m_size; }
    virtual T next() {
        if (!has_next()) {
            throw -1;
        }
        return m_arr[m_index++];
    }
private:
    const T * m_arr;
    int m_size;
    int m_index;
};

template <typename T>
class MergedIterator : public Iterator<T> {
public:
    MergedIterator(Iterator<T> ** arr, int size): m_arr(arr), m_size(size), m_index(0) {}
    virtual ~MergedIterator() {}
    virtual bool has_next() {
        while (m_index < m_size && !m_arr[m_index]->has_next()) {
            m_index++;
        }
        return m_index < m_size;
    }
    virtual T next() {
        if (!has_next()) {
            throw -1;
        }
        return m_arr[m_index]->next();
    }
private:
    Iterator<T> ** m_arr;
    int m_size;
    int m_index;
};

int main(int argc, const char ** argv) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    Iterator<int> * iterator1 = new ArrayIterator<int>(arr, size);
    Iterator<int> * iterator2 = new ArrayIterator<int>(arr, size - 1);
    Iterator<int> * iterators[] = {iterator1, iterator2};
    Iterator<int> * iterator = new MergedIterator<int>(iterators, 2);
    while (iterator->has_next()) {
        cout << iterator->next() << endl;
    }
    delete iterator;
    delete iterator1;
    delete iterator2;
    return 0;
}
