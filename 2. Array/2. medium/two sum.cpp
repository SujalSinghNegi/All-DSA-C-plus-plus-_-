class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //unordered_map<int,int>mpp;
        vector<pair<int,int>>mpp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mpp.push_back({nums[i],i});
        }
        sort(mpp.begin(), mpp.end());
        int i=0, j=n-1;
        while(i<j){
            int x=mpp[i].first+mpp[j].first;
            if(x== target) return {mpp[i].second, mpp[j].second};
            if(x<target)i++;
            else j--;
        }
        return{};
    }
};