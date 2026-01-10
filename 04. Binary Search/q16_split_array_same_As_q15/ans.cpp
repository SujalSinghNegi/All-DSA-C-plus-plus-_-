class Solution {
public:
bool check(vector<int>&arr, int mid, int k){
    int n = arr.size();
    int sum =0, cnt =1;
    for(int i=0; i<n; i++){
        if(sum+ arr[i] <= mid){
            sum+= arr[i];
        }else{
            sum =arr[i];
            cnt++;
        }
    }
    return cnt <=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low ) /2;
            if(check(nums, mid, k)){
                ans =min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};