
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0, n=1;
        vector<int>ans(nums.size());
        for(auto it:nums){
            if(it>0){
                ans[p]=it;
                p+=2;
            }else{
                ans[n]=it;
                n+=2;
            }
        }
        return ans;
    }
};