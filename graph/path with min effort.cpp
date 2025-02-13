class Solution {
  public: 
  struct node{
      int mad, row, col;
  };
  struct compare {
    bool operator()(const node& a, const node& b) {
        return a.mad > b.mad; 
    }
};
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        
        vector<vector<int>>hike(rows, vector<int>(columns,1e9));
        hike[0][0]=0;
        priority_queue<node, vector<node>, compare>q;
        q.push({0,0,0});
        while(!q.empty()){
            auto a= q.top();
            q.pop();
            int mad= a.mad;
            int row= a.row;
            int col= a.col;
            if(row==rows-1 && col == columns-1) return mad;
           
            int dx[]={0,0,-1,+1};
            int dy[]={1,-1,0,0};
            for(int i=0; i<4; i++){
                int r= row+dx[i];
                int c= col+dy[i];
                if(r>=0 && c>=0 && r<rows && c< columns){
                int m= abs(heights[row][col]-heights[r][c]);
                if(hike[r][c] > max(m,mad) ){
                     hike[r][c]=max(m,mad);
                    // cout<<"pushed="<<m<<" "<<mad<<" "<<r<<" "<<c<<" ";
                    q.push({max(m, mad), r, c});
                }
                }
            }
           // cout<<endl;
        }
        return hike[rows-1][columns-1];
    }
};
