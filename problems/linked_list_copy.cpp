// http://www.glassdoor.com/Interview/Amazon-com-Software-Development-Engineer-I-Interview-Questions-EI_IE6036.0,10_KO11,42.htm#RVW3335897
// Interview Question – Deep copy of a list list containing a pointer to the next node and also a pointer to a random other node ( could be a node ahead in the list, the node itself, somewhere behind or NULL)
#include <map>

struct Node {
    Node * next;
    Node * item;
};

Node * copy(Node * root) {
    if (!root) {
        return NULL;
    }
    
    std::map<Node*, Node*> node_map;
    Node * orig = root;
    Node * prev = NULL;
    Node * curr = NULL;
    while (orig) {
        prev = curr;
        curr = new Node();
        curr->next = NULL;
        curr->item = NULL;
        if (prev) {
            prev->next = curr;
        }
        node_map[orig] = prev;
        orig = orig->next;
    }

    orig = root;
    while (orig) {
        if (orig->item) {
            node_map[orig]->item = node_map[orig->item];
        }
        orig = orig->next;
    }
    
    return node_map[root];
}

int main(int argc, const char ** argv) {
    return 0;
}