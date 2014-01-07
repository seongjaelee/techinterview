# IT Technical Interview

## Data Structures
- abstract: queue, stack, priority queue, list, array, set
- trees: b-tree, binary search tree (AVL, red-black, splay), heap, trie, traversal
- graphs: representation, traversal, Dijkstra and A*
- sort: quick sort, merge sort, heap sort
- hash

## Hash
- hash function
    - uniformness mastters
    - clustering also matters for open hashing
    - cryptographic hashing, universal hashing: prevent sabotage
- load factor
- collision resolution
    - open hashing = closed addressing = separate chaining
        - linked list
    - closed hashing = open addressing
        - probe sequence: linear, quadratic, double hashing
        - lazy deletion
        - clustering matters
        - suffers a lot from high load factor
- dynamic resizing, rehashing
- properties
    - advantages: speed
    - disadvantages: locality of reference, collisions, memory
- code
    - `basics/hash_open.cpp`
    - `basics/hash_closed.cpp`

## Tree
- binary, n-ary, trie
- traversal: bfs, dfs
    - dfs: in-order, pre-order, post-order
    - code: `basics/tree_traversal.cpp`
- self-balancing binary search tree
    - red-black tree: root and leaves are black, red's children should be black
    - avl tree: children height diff should be less than 2
    - splay tree: ?

### Trie
- trie vs. hashtable
    - yes, no hash function, no collision
    - but what if the key is very, very long? memory?
- radix sort O(kN)
- code: `basics/trie.cpp`

### AVL Tree
- traversal: amortized 2, worst case 2d
- property: balance factor = |left height - right height| <= 1, rotate left/right
- insertion: insert it, update heights and balance
- deletion: locate, swap with the next leaf, delete that, update heights and balance
- balancing: ll, lr, rl, rr four cases
- code: `bascis/tree_avl.cpp`

## Graph
- `adjacent(u, v)`, `neighbors(u)`, `add_edge`, `delete_edge`
- `set/get_node_value`, `set/get_edge_value`
- representations: objects and pointers, adjacency list, adjacency matrix
    - adjacency matrix O(V^2), adding/removing vertex O(V^2)
    - adjacency list O(V+E), removing vertex/edge O(E)
- traversal: dft, bft
- algorithms
    - Dijkstra: breadth-first and priority queue. the single-source shortest path problem for a graph with non-negative edge path costs, producing a shortest path tree. O(ElogV + VlogV).
    - A*: breath-first search, heuristics h s.t. d(x) <= d(x,y) + h(y), O(logh(x))
    - Dijkstra is a special case for A* (when the heuristics is zero).

## Sort
| Name      | Best     | Worst    | Memory  | Comment |
| Insertion | O(n)     | O(n^2)   | O(1)    | O(n+d) when d = # of inversions |
| Quick     | O(nlogn) | O(n^2)   | O(logn) |  |
| Merge     | O(nlogn) | O(nlogn) | O(n)    | linked list, memory O(1), large data, parallel |
| Heap      | O(nlogn) | O(nlogn) | O(logn) | unstable |