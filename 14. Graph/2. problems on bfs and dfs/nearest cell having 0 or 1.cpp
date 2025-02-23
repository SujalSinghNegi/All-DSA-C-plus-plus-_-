class Solution {
public:
    typedef struct crazy{
        int row, col, tm;
    }crazy;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m= mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
         queue<crazy>q;
            for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i, j, 0});
                }
            }
        }
         vector<pair<int,int>>di={{-1,0},{0,-1}, {1,0}, {0,1} };
         while(!q.empty()){
            crazy node=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow= di[i].first+node.row;
                int ncol= di[i].second+node.col;
                if(nrow>=0 && ncol>=0 && nrow<n&& ncol<m && mat[nrow][ncol]==1&& (ans[nrow][ncol]==-1 || ans[nrow][ncol] > node.tm+1 )){
                    ans[nrow][ncol]=node.tm +1;
                    q.push({nrow, ncol, node.tm+1});
                }
            }
         }
         return ans;
    }
};