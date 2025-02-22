class Solution {
  public:
  struct node {
    int level, row, col;
    
  };

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n= grid.size();
        int m=grid[0].size();
    queue<node>pq;  // Min-heap based on `level`
    vector<vector<int>>dist(n, vector<int>(m,1e9));
    pq.push({0,source.first,source.second});
    dist[source.first][source.second]=0;
    while(!pq.empty()){
        auto a=pq.front();
        pq.pop();
        int row= a.row;
        int col= a.col;
        int lvl= a.level;
        if(row==destination.first && col == destination.second ) return lvl;
        int dx[]={0,0,-1,+1};
        int dy[]={-1,+1,0,0};
        for(int i=0; i<4; i++){
            int r= dx[i]+row;
            int c= dy[i]+col;
            if(r>=0 && c>=0 && r<n&& c<m &&  lvl+1 < dist[r][c] && grid[r][c]==1 ){
                dist[r][c]=lvl+1;
                pq.push({lvl+1, r, c});
            }
        }
    }
  return -1;
        
    }
};