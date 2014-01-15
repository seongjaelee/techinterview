#include <vector>
#include <queue>
#include <set>
using namespace std;

struct node {
    vector<node *> targets;
};

// do i need to check only if such a route exists or not?
// do i need to find the sortest route?
// do i need to specify the route?
bool check_route(node * s, node * g) {
    queue<node *> q;
    set<node *> visited;
    q.push(s);

    while (!q.empty()) {
        node * u = q.front();
        q.pop();
        if (u == g) {
            return true;
        }
        visited.insert(u);
        for (vector<node *>::iterator it = u->targets.begin(); it != u->targets.end(); ++it) {
            node * v = *it;
            if (visited.find(v) == visited.end()) {
                q.push(v);
            }
        }
    }
    return false;
}

int main(int argc, const char ** argv) {
    return 0;
}