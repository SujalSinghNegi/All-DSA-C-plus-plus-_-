class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // what i can see from this problem is we have to find first that the all numbers in a grid should have the equal rem with the x,
        // we get the array multiple of the number wrt to x
        // this array shows if we add or sub in each cell such that the no. equal to the highest number present
        // sort the array to find the median
      // now subtract the median to each number and then take the abs of it then return the results


        int n= grid.size(), m= grid[0].size();
        int rem = grid[0][0]%x;
        int sum=0;
        vector<int>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]%x != rem) return -1;
                sum+= grid[i][j]/x;
                ans.push_back(grid[i][j]/x);
            }
        }
        int res = 0;
        sort(ans.begin(), ans.end());
        int minis = ans[ans.size() / 2];

        for(auto it:ans){
            res+=abs(it-minis);
        }
        return res;
    }
};