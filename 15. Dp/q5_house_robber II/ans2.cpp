class Solution {
    public:
        int robHelper(vector<int>& arr, int start, int end) {
            int next1 = 0, next2 = 0;
            for (int i = end; i >= start; i--) {
                int curi = max(next1, next2 + arr[i]);
                next2 = next1;
                next1 = curi;
            }
            return next1;
        }
    
        int rob(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0];
            return max(robHelper(arr, 0, n - 2), robHelper(arr, 1, n - 1));
        }
    };
    