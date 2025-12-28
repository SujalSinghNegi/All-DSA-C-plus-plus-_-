
// BOTH ARE SAME NO DIFFERENCE
#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                left[i] = max(left[i], left[j] + 1);
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                right[i] = max(right[i], right[j] + 1);
            }
        }
    }
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] > 1 && right[i] > 1) {
            maxLength = max(maxLength, left[i] + right[i] - 1);
        }
    }
    return maxLength < 3 ? 0 : maxLength;
}

int main() {
  
    vector<int> arr = {12, 11, 40, 5, 3, 1};

    cout << LongestBitonicSequence(arr) << endl;
    return 0;
}