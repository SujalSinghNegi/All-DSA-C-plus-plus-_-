// Graph Diameter
// Difficulty: MediumAccuracy: 72.93%Submissions: 1K+Points: 4

// You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertex u and vertex v. Find the diameter of the graph.
// The diameter of a graph (sometimes called the width) is the number of edges on the longest path between two vertices in the graph.

// Examples :

// Input: V = 6, E = 5, edges[][] = [[0, 1], [0, 4], [1, 3], [1, 2], [2, 5]]
    
// Output: 4
// Explanation: The longest path in the graph is from vertices 4 to vertices 5 (4 -> 0 -> 1 -> 2 -> 5).

// Input: V = 7, E = 6, edges[][] = [[0, 2], [0, 4], [0, 3], [3, 1], [3, 5], [1, 6]]
    
// Output: 4
// Explanation: The longest path in the graph is from vertices 2 to vertices 6 (2 -> 0 -> 3 -> 1 -> 6).

// Constraints:
// 2 ≤ V ≤  105
// 1 ≤ E ≤  V - 1
// 0 ≤ edges[i][0], edges[i][1] < V


class Solution {
  public:
  int maxa = INT_MIN;
  
    int dfs(int node, vector<vector<int>>&adj, vector<int> & vis){
        vis[node] =1;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto child: adj[node]){
           if(!vis[child]) pq.push(dfs(child, adj, vis));
           if(pq.size() > 2)pq.pop();
        }
        int maxa1 = 0, maxa2=0;
        if(!pq.empty() ){maxa1 = pq.top(); pq.pop();}
         if(!pq.empty() ){maxa2 = pq.top(); pq.pop();}
        maxa = max(maxa, maxa1+maxa2);
        return max(maxa1, maxa2) + 1;
        
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        int n = V;
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n, 0);
       
            dfs(0, adj, vis);
        
        return maxa;
    }
};

