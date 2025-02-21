class Solution {
public:
    bool back(vector<vector<int>>&vis, vector<vector<char>>& board, string &word, int row, int col, int ind,int s, int n, int m){
        if(ind == s) return 1;
        vis[row][col]=1;
        int dx[]= {0,0,1,-1};
        int dy[]= {-1,1,0,0};
        for(int k=0; k<4; k++){
            int nrow = dx[k]+row;
            int ncol= dy[k]+col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && 
            !vis[nrow][ncol] &&  board[nrow][ncol]==word[ind]){
                if(back(vis, board, word, nrow, ncol, ind+1, s, n, m)) return 1;
            }
        }
        vis[row][col]=0;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int s= word.size();
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]==word[0]){
                    if(back(vis, board, word, i, j, 1, s, n, m))return 1;
                }
            }
        }
        return 0;
    }
};