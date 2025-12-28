class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0,high = n-1;
        if(n == 1) return arr[0];
        while(low<=high){
            int mid = low + (high- low)/2;
            if((mid == 0 || mid == n-1) || arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            if(mid&1){
                if(arr[mid-1] == arr[mid]) low = mid+1;
                else high = mid;
            }else{
                if(arr[mid+1] == arr[mid]) low = mid+1;
                else high = mid ;
            }
        }
        return -1;
    }
};