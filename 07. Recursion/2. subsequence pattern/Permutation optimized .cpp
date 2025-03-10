
class Solution {
  public:
  void backtrack(vector<int>&s, int n, int ind,vector<vector<int>>&ans){
      if(ind==n){
          ans.push_back(s);
          return;
      }
      
      for(int i=ind; i<n; i++){
          if(i>ind && s[i-1]==s[i])continue;
          swap(s[i], s[ind]);
          backtrack(s, n, ind+1, ans);
           swap(s[i], s[ind]);
      }
  }
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>>ans;
         sort(s.begin(), s.end());
        int n=s.size();
        //vector<vector<int>>ans;
        backtrack(s, n, 0,ans);
        return ans;
    }
};