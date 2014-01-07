#include <stack>
#include <iostream>

using std::stack;

template <typename T>
class queue {
public:
    T dequeue();
    void enqueue(T item);
    bool empty() const;
private:
    stack<T> m_istack;
    stack<T> m_ostack;
};

template <typename T>
void queue<T>::enqueue(T item) {
    m_istack.push(item);
}

template <typename T>
T queue<T>::dequeue() {
    if (m_ostack.empty()) {
        while (!m_istack.empty()) {
            m_ostack.push(m_istack.top());
            m_istack.pop();
        }
    }
    if (!m_ostack.empty()) {
        T ret = m_ostack.top();
        m_ostack.pop();
        return ret;
    }
    throw 0;
}

template <typename T>
bool queue<T>::empty() const {
    return m_istack.empty() && m_ostack.empty();
}

int main(int argc, const char ** argv) {
    queue<int> q;
    q.enqueue(3);
    q.enqueue(2);
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;

    try {
        std::cout << q.dequeue() << std::endl;
    }
    catch (int e) {

    }
    
    return 0;
}