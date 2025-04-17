#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Depth-First Search to mark all reachable vertices from node `v`.
     */
    void dfs(int v, vector<int> adj[], vector<bool> &visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u, adj, visited);
        }
    }

    /**
     * Checks if all non-zero degree vertices are connected.
     */
    bool IsConnected(int V, vector<int> adj[]) {
        int node = -1;

        // Find a vertex with non-zero degree
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                node = i;
                break;
            }
        }

        // If there are no edges, graph is trivially connected
        if (node == -1)
            return true;

        // Perform DFS from a vertex with non-zero degree
        vector<bool> visited(V, false);
        dfs(node, adj, visited);

        // Check if all non-zero degree vertices are visited
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty() && !visited[i])
                return false;
        }

        return true;
    }

    /**
     * Function to determine whether the undirected graph contains:
     * - 0 : No Euler path or circuit
     * - 1 : Euler path but not Euler circuit
     * - 2 : Euler circuit
     */
    int isEulerCircuit(int V, vector<int> adj[]) {
        if (!IsConnected(V, adj))
            return 0;

        int oddCount = 0;

        // Count vertices with odd degree
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                oddCount++;
        }

        if (oddCount > 2)
            return 0;       // No Euler path or circuit
        else if (oddCount == 2)
            return 1;       // Euler path (but not circuit)
        else
            return 2;       // Euler circuit
    }
};
