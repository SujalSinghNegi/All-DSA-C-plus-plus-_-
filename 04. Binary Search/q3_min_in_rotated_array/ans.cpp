class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high= n-1;
        while(low<=high){
            int mid = low + (high -low) /2;
            if(arr[low] <= arr[high]) return arr[low];
            if(arr[low] <= arr[mid]) low =mid+1;
            else high = mid;
        }
        return arr[low];
    }
};