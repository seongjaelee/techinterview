#include <vector>
#include <queue>
#include <limits>
using namespace std;

void dijkstra(int * graph, int n, int s) {
    vector<int> costs(n, numeric_limits<int>::max());
    vector<int> prevs(n, -1);
    queue<int> q;

    costs[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (graph[u * n + v] <= 0) {
                continue;
            }
            int new_cost = costs[u] + graph[u * n + v];
            if (costs[v] > new_cost) {
                costs[v] = new_cost;
                prevs[v] = u;
                q.push(v);
            }
        }
    }

    printf("src tgt cst\n");
    for (int u = 0; u < n; ++u) {
        printf("%3d %3d %3d\n", u, prevs[u], costs[u]);
    }
}

int main(int argc, const char ** argv) {
    // http://en.wikipedia.org/wiki/Dijkstra's_algorithm
    int graph[] = { 0,  7,  9,  0,  0, 14,
                    7,  0, 10, 15,  0,  0,
                    9, 10,  0, 11,  0,  2,
                    0, 15, 11,  0,  6,  0,
                    0,  0,  0,  6,  0,  9,
                   14,  0,  2,  0,  9,  0};
    int n = 6;
    dijkstra(graph, n, 0);
    return 0;
}