class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n= mat.size();
       // vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==-1){
                    mat[i][j]=1e9;
                }
                if(i==j) mat[i][j]=0;
            }
        }
       //  via 0
       //from 0 to 1, 0-0 0-1, 0-0 0-2, 0-0 0-3, 0-0 0-4,
       // from a to b, a-0 0 -b
       
       // via k
       // from i to j, i-k, j-b
        for(int k=0; k<n; k++){
               for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j]= min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
        
        }
        
           for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1e9){
                    mat[i][j]=-1;
                }
              
            }
        }
        
    }
};