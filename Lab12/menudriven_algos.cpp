//To Make a menu driven program for prims , kruskals and dijkstra's algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// --------- Edge Struct ----------
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// --------- DSU Class Declaration ----------
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n);
    int find(int x);
    bool unite(int x, int y);
};

// --------- Graph Class Declaration ----------
class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<Edge> edges;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void prims();
    void kruskal();
    void dijkstra(int src);
};

// --------- Main Function ----------
int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Edge\n2. Prim's MST\n3. Kruskal's MST\n4. Dijkstra\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter u v w: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.prims();
        } else if (choice == 3) {
            g.kruskal();
        } else if (choice == 4) {
            int src;
            cout << "Enter source: ";
            cin >> src;
            g.dijkstra(src);
        } else if (choice == 5) {
            cout<<"Exiting.."<<endl;
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

// --------- DSU Function Definitions ----------
DSU::DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

int DSU::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool DSU::unite(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr) return false;
    if (rank[xr] < rank[yr]) parent[xr] = yr;
    else if (rank[xr] > rank[yr]) parent[yr] = xr;
    else { parent[yr] = xr; rank[xr]++; }
    return true;
}

// --------- Graph Function Definitions ----------
Graph::Graph(int V) : V(V) {
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edges.push_back({u, v, w});
}

void Graph::prims() {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int i = 0; i < V - 1; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j)
            if (!inMST[j] && (u == -1 || key[j] < key[u]))
                u = j;

        inMST[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "\nPrim's MST:\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\n";
}

void Graph::kruskal() {
    DSU dsu(V);
    sort(edges.begin(), edges.end());

    cout << "\nKruskal's MST:\n";
    for (auto &e : edges)
        if (dsu.unite(e.u, e.v))
            cout << e.u << " - " << e.v << "\n";
}

void Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nDijkstra's from " << src << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "To " << i << " : " << dist[i] << "\n";
}
