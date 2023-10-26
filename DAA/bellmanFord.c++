#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Edge {
public:
    int src, dest, wt;
    Edge(int src, int dest, int wt) : src(src), dest(dest), wt(wt) {}
};

void createGraph(vector<Edge>& graph) {
    graph.push_back(Edge(0, 1, 2));
    graph.push_back(Edge(0, 2, 4));
    graph.push_back(Edge(1, 2, -4));
    graph.push_back(Edge(2, 3, 2));
    graph.push_back(Edge(3, 4, 4));
    graph.push_back(Edge(4, 1, -1));
}

void bellmanFord(vector<Edge>& graph, int src, int V) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& e : graph) {
            int u = e.src;
            int v = e.dest;
            int wt = e.wt;

            if (dist[u] != numeric_limits<int>::max() && dist[u] + wt < dist[v]) {
                dist[v] = wt + dist[u];
            }
        }
    }

    cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<Edge> graph;
    createGraph(graph);
    int src = 0;
    bellmanFord(graph, src, V);

    return 0;
}
