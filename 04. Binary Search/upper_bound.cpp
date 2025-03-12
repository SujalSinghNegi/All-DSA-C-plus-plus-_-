// find the upper bound of a number in a sorted array
// upper bound is the smallest number greater than to the given number
//arr[ind] > x 
//  ub= upper_bound(arr.begin(), arr.end(), x) - arr.begin(); // stl function

int upper_bound(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0, high = n- 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >  x) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    } 
    return ans;
    }
    