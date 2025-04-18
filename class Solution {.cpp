class Solution {
  public:
    bool isBeauty(vector<vector<int>> &mat) {
        // code here
        vector<int>col;
        for(auto it:mat){
          int sum=0;
          for(auto bt:it){
            sum+=bt;
          }
          col.push_back(sum);
        }
        bool ans=1;
        for(int i=0;i<mat.size();i++){
          bool f=0;
          for(int j=0;j<mat[0].size();j++){
            if(mat[i][j] == sum-mat[i][j]){
              f=1;
              break;
            }
          }
          if(!f)return 0;
        }
        return 1;
    }
};