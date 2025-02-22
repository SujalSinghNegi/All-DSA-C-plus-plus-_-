class Solution {
public:
    void back(vector<vector<int>>&ans, vector<int>&ds, int n, int k, int ind, vector<int>&all, int sum){
        if(ind ==k){
            if(sum==n){
                ans.push_back(ds);
                return;
            }
        }
       int i = ind?ds.back()+1 : 1;
        for(; i<=9; i++){
            if(!all[i] && sum+i <= n){
                ds.push_back(i);
                all[i]=1;
                back(ans, ds, n, k, ind+1, all, sum+i);
                ds.pop_back();
                all[i]=0;

            }else if(sum+i > n) break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>all(10, 0);
        back(ans, ds, n,k , 0, all, 0);
        return ans;
    } 
};