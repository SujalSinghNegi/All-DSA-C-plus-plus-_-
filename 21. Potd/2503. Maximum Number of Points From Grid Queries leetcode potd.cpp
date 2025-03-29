class Solution {
public:
typedef struct cell{
    int val, r, c;
     bool operator>(const cell& other) const {
        return val > other.val;
    }
}cell;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m= grid[0].size();
        // i will query for the size of the queriy
        // make a map it store the queries in a sorted manner as i travers the map it will give me the each querry and after that i get those number i will change the mpp[q]= count;
        // as the count is inc only not reseting it will always give the correct answer and we dont have to explictly define that dp[i]= dp[i-1] +cnt,not requeried as we are not reseting the cnt;
        int k=queries.size();
        map<int,int>mpp;
       for(int i=0;i<k; i++){
        mpp[queries[i]]=0;
       }
       // this pq will store the node in sorted manner that why we will not miss any node in the any bfs 
        priority_queue<cell,vector<cell>, greater<cell>>pq;
        pq.push({grid[0][0], 0, 0});
        vector<int>dp(k, 0);
        int cnt=0;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        vis[0][0]=true; // imp so that the another node dont visit it twice
      int j=0;
      for(auto it:mpp){
        while(!pq.empty() &&  pq.top().val<it.first){
            cell cur= pq.top();
            pq.pop();
            cnt++;
            for(int i=0; i<4; i++){
                int nr = dx[i]+cur.r;
                int nc=dy[i]+cur.c;
                if(nr>=0 && nr<n && nc>=0 && nc<m  && !vis[nr][nc]) { // dont have to include the grid[nr][nc]<cur.val , because in this step we just intrest in bfs , that's why this condintion is put on the while loop condition, that the only correct node will inc the points;
                    
                    pq.push({grid[nr][nc], nr, nc});
                    vis[nr][nc]=true;
                }
            }

        }
        mpp[it.first]=cnt;
      }
      // here the index wise the dp array is filled with help of query and mpp
      for(int ind=0; ind<k; ind++){
        dp[ind]=mpp[queries[ind]];

      }
        return dp;
    }
};