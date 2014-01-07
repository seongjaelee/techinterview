#include <cstddef>
#include <iostream>

struct Node {
    int item;
    Node * next;
};

Node * reverse(Node * head) {
    Node * prev = NULL;
    Node * curr = NULL;
    Node * next = NULL;

    prev = NULL;
    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node * delete(Node * head, Node * node_to_delete) {
    if (node_to_delete == head) {
        head = head->next;
        delete node_to_delete;
        return;
    }

    Node * node = head;
    while (node) {
        if (node->next == node_to_delete) {
            node->next = node->next->next;
            delete node_to_delete;
            return head;
        }
        node = node->next;
    }
    
    assert(false);
}

void print(Node * head) {
    Node * node = head;
    while (node) {
        std::cout << node->item << ":";
        node = node->next;
    }
    std::cout << std::endl;
}

Node * create(int * arr, int n) {
    Node * head = NULL;
    for (int i = 0; i < n; ++i) {
        Node * node = new Node();
        node->item = arr[i];
        node->next = head;
        head = node;
    }
    return head;
}

void clean(Node * head) {
    Node * node = head;
    Node * next = NULL;
    while (node) {
        next = node->next;
        delete node;
        node = next;
    }
}

int main(int argc, const char ** argv) {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    Node * head = create(arr, 10);
    print(head);
    head = reverse(head);
    print(head);
    clean(head);
    return 0;
}