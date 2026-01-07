#define ll long long
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int save = high;
        int n = nums.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            ll sum =0;
            for(int i =0 ;i<n; i++){
               sum+= (nums[i] + mid - 1)/ mid;
            }
            if(sum > threshold){
                low = mid+1;
            }else{
                save = min(save, mid);
                high =mid-1;
            }
        }
        return save;
    }
};