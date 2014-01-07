#include <iostream>

using namespace std;

struct node {
    int item;
    node * next;
};

node * insert_node(node * head, int item) {
    node * curr = new node();
    curr->item = item;
    curr->next = head;
    return curr;
}

node * delete_node(node * head, int item) {
    if (head->item == item) {
        node * ret = head->next;
        delete head;
        return ret;
    }

    node * curr = head;
    while (curr) {
        if (curr->next->item == item) {
            node * todelete = curr->next;
            curr->next = curr->next->next;
            delete todelete;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

node * create(int * arr, int size) {
    if (size == 0) {
        return NULL;
    }
    node * root = NULL;
    node * prev = NULL;
    for (int i = 1; i < size; ++i) {
        node * node = new struct node();
        node->item = arr[i];
        node->next = NULL;
        if (prev) {
            prev->next = node;
        }
        if (!root) {
            root = node;
        }
        prev = node;
    }
    return root;
}

node * reverse(node * curr) {
    node * prev = NULL;
    node * next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void clear(node * curr) {
    node * next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void print(node * node) {
    while (node) {
        cout << node->item << ", ";
        node = node->next;
    }
    cout << endl;
}

int main(int argc, const char ** argv) {
    int arr[] = {0, 1, 2, 3, 4};
    int arr_size = sizeof(arr) / sizeof(int);
    node * head = create(arr, arr_size);
    print(head);
    head = reverse(head);
    print(head);
    head = delete_node(head, 2);
    print(head);
    head = delete_node(head, 4);
    print(head);
    head = insert_node(head, 5);
    print(head);
    clear(head);
    return 0;
}