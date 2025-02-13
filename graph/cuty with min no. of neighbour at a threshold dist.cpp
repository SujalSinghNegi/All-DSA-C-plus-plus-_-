class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; i++) mat[i][i] = 0;
        
        for (int j = 0; j < m; j++) {
            int a = edges[j][0];
            int b = edges[j][1];
            mat[a][b] = min(edges[j][2], mat[a][b]);
            mat[b][a] = min(edges[j][2], mat[b][a]);
        }
        
        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] == 1e9 || mat[k][j] == 1e9) continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        
        int mini = n, ans = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] <= k) cnt++;
            }
            // Update the city with the least reachable cities
            if (cnt <= mini) { 
                mini = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};
