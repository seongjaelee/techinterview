// Write a function to tell whether a BST is balanced 
// http://www.glassdoor.com/Interview/Amazon-com-Software-Development-Engineer-Interview-Questions-EI_IE6036.0,10_KO11,40.htm#RVW3381094

struct node {
    node * l;
    node * r;
};

bool is_balanced_internal(node * node, int depth, int & min_depth, int & max_depth) {
    if (node == NULL) {
        if (min_depth == -1) {
            min_depth = depth;
            return true;
        }
        if (max_depth == -1) {
            if (min_depth == depth) {
                return true;
            }
            if (min_depth == depth + 1) {
                min_depth = depth;
                max_depth = depth + 1;
                return true;
            }
            if (min_depth == depth - 1) {
                max_depth = depth;
                return true;
            }
            return false;
        }
        return (depth == min_depth || depth == max_depth);
    }

    return is_balanced(node->l, depth + 1, min_depth, max_depth) && is_balanced(node->l, depth + 1, min_depth, max_depth);
}

bool is_balanced(node * node) {
    int min_depth = -1;
    int max_depth = -1;
    return is_balanced_internal(node, 0, min_depth, max_depth);
}