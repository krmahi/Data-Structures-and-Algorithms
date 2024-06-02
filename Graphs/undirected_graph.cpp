// using a adjacency matrix to represent a graph
// time complexity: O(n^2) || O(n + 1 * m + 1)

int main()
{
    int n, m;
    std::cin >> n >> m;
    int adj[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // remove for directed graph
    }
    return 0;
}

// using a adjacency list to represent a graph
//  time complexity: O(2e) | for directed O(e) => e == edges

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1] for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }
    return 0;
}