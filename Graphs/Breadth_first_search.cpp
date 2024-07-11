// time complexity: O(N) + O(2E)
// no. of total edges i.e. degrees (for the for loop)
// space complexity: O(N) + O(N) + O(N) = O(N)
// for the queue, for the vis array, for the bfs array
class solution
{
public:
    vector<int> bfs_graph(int v, vector<int> adj[])
    {
        int vis[n] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
    }
};