class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n =arr.size();
        int low = 0, high = n-1;
        while(low<= high){
            int mid = low + (high -low) /2;
            if(arr[low] <= arr[high]) return low;
            if(arr[low] <= arr[mid]) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
