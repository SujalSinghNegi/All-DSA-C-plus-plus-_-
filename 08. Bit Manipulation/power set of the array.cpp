class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n= nums.size();
        int num=1;
        num<<=n;
        for(int i=0; i<num; i++){
            vector<int>temp;
            for(int j=0; j<n; j++){
                if(1<<j & i){
temp.push_back(nums[j]);
                }
            }
ans.push_back(temp);

        }
        return ans;
    }
};