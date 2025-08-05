class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
         int  n = mat.size();
         int i=0, j =n-1;
    while(i<j){
        if(mat[i][j]==0 || mat[j][i]==1)j--;
        else if(mat[j][i]==0 | mat[i][j]==1) i++;
    }
    if(i!=j) return -1;
    for(int ind=0; ind<n; ind++){
       if(( mat[ind][i] ==0) || i!= ind && mat[i][ind]!=0)return -1; 
    }
    return i;
    }
};