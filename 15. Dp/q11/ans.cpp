class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for ( int  i = n-2 ; i >=0 ;i--){
            for( int j = 0; j<n; j++){
                int left = 1e9,  right=1e9;
                if(j>0)left = matrix[i+1][j-1];
                if(j<n-1)right = matrix[i+1][j+1];
                matrix[i][j]+= min({left, matrix[i+1][j], right});
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};