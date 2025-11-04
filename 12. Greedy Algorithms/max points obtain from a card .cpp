
// 1423. Maximum Points You Can Obtain from Cards
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

// Example 1:

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

// Example 2:

// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

// Example 3:

// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.

 

// Constraints:

//     1 <= cardPoints.length <= 105
//     1 <= cardPoints[i] <= 104
//     1 <= k <= cardPoints.length




class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        // sliding window, but that works like doing on a rotated array
        // first make window of first k elements , then move window to the left,  that is dec from the leftSide and inc from the RightMost side till the complete window came to the right 

        int n = arr.size();
        int sum = 0, maxa = 0, j=k-1;
        for(int i=0; i<k; i++)sum+= arr[i];
        maxa = sum;
        for(int i = n-1; i>=n-k; i--){
            sum-= arr[j--];
            sum+= arr[i];
            maxa = max(maxa, sum);
        }
        return maxa;
    }
};

// --------my approach -------
// instead of finding max sum of k elements from start or end, we can find min sum of n-k elements in between and subtract it from total sum

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
       int save = 0, mini=INT_MAX, p= n-k, sum=0;
       for(int i=0; i<n; i++){
        sum+= arr[i];
       if(i-p >= 0) sum-= arr[i-p];
        if(i-p+1>=0 && sum<mini) {
            mini= sum;
            save = i;
        }
       }
       mini -= accumulate(arr.begin(), arr.end(),0);
      return  -mini ;
    }
};
   