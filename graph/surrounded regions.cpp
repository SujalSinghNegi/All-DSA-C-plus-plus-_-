class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board,vector<vector<bool>>& vis ,int n,int m){
        vis[i][j]=1;
      //  cout<<"i="<<i<<"j="<<j<<endl;
        int dx[4]={-1, +1, 0, 0};
        int dy[4]={0, 0, -1, +1};
        for(int k=0; k<4; k++){
            int nrow= dx[k]+i;
            int ncol= dy[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                 vis[nrow][ncol]=1;
                dfs(nrow, ncol, board, vis,  n, m);

            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size(), m= board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        int first=0, end=m;
        for(int i=0; i<n; i++){
            if(i==0 || i==n-1){
                for(int j=0; j<m; j++){
                    if(board[i][j]=='O' && !vis[i][j]){
                         vis[i][j]=1;
                      //   cout<<"hello";
                        dfs(i, j, board, vis,  n, m);
                    }
                }
            }else{
                if(board[i][0]=='O' && !vis[i][0]){
                    vis[i][0]=1;
                    dfs(i, 0, board, vis,  n, m);
                }
                if(board[i][m-1]=='O' && !vis[i][m-1]){
                    vis[i][m-1]=1;
                    dfs(i, m-1, board, vis,  n, m);
                }

            }
        }
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }
      
    }
};