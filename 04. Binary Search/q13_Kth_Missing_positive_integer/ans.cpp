class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        if(arr.back() - n < k) return k + n;
        if(arr[0] > k) return k;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] - mid-1 >= k){
                if(arr[mid-1] - mid < k) return k + mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;

    }
};