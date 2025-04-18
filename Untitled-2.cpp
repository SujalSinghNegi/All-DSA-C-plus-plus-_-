#include <bits/stdc++.h>
using namespace std;

/*
  Function to return the length of the longest subarray
  in which every element <= subarray length.
*/
int longestSubarrayLength(const vector<int>& arr) {
    int n = (int)arr.size();
    if (n == 0) return 0;
    
    // Deque will store indices; arr[dq.front()] is the maximum in the current window.
    deque<int> dq;
    int left = 0;
    int ans = 0;
    
    for (int right = 0; right < n; ++right) {
        // 1) Maintain deque for max:
        // Pop from back while current element is >= arr[dq.back()].
        while (!dq.empty() && arr[dq.back()] <= arr[right]) {
            dq.pop_back();
        }
        dq.push_back(right);
        
        // 2) Now ensure the window [left..right] is valid:
        //    The maximum in this window must be <= (right - left + 1).
        //    The maximum is arr[dq.front()].
        while (!dq.empty() && arr[dq.front()] > (right - left + 1)) {
            // If the front of deque is out of the window once we move left, pop it.
            if (dq.front() == left) {
                dq.pop_front();
            }
            left++;
        }
        
        // 3) Update the answer with the current valid window size.
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage:
    // Input format is not strictly defined here, but let's assume:
    //  1) An integer n (size of array)
    //  2) n space-separated integers (elements of arr)
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << longestSubarrayLength(arr) << "\n";
    return 0;
}
