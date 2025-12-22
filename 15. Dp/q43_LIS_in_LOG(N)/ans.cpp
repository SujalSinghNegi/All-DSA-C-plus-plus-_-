class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp; // temp is not storing the lis, it is just simulating the list , but not actually storing it, the sequence that store in this temp array are stored in such a way that, the smaller number if found in place of the bigger number previously they can possibly form the largest length lis, if all the numbers till temp.size() are replaced, and although if they dont form the biggest list, but the lis length that is currently bigger its length is still preserverd although the number are gone .
        int ans= 0;
        for(int i= 0; i<n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            if(it == temp.size())temp.push_back(nums[i]);
            else temp[it] = nums[i];
        }
        return temp.size();
    }
};