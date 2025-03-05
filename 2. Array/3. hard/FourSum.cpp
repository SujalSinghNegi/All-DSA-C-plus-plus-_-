//Four Sum ,exact similar to 3 sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int t = 0; t < n - 3; t++) {
            if (t > 0 && nums[t] == nums[t - 1])
                continue;
            for (int i = t + 1; i < n - 2; i++) {
                if (i > t + 1 && nums[i] == nums[i - 1])
                    continue;
                int j = i + 1, k = n - 1;
                while (j < k) {
                    long int sum = long(nums[t]) + long(nums[i]) +
                                   long(nums[j]) + long(nums[k]);
                    if (sum < target)
                        j++;
                    else if (sum > target)
                        k--;
                    else {
                        ans.push_back({nums[t], nums[i], nums[j], nums[k]});
                        j++;
                        k--;

                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                        while (j < k && nums[k] == nums[k + 1])
                            k--;
                    }
                }
            }
        }
        return ans;
    }
};