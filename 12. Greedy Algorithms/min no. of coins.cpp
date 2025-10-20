// Minimum number of Coins
// Difficulty: EasyAccuracy: 51.25%Submissions: 103K+Points: 2

// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to make the change for Rs n. 

// Examples:

// Input: n = 39
// Output: 6
// Explaination: 39 can be formed using 3 coins of 10 rupees, 1 coin of 5 rupees and 2 coins of 2 rupees so minimum coins required are 6.

// Input: n = 121
// Output: 13
// Explaination: 121 can be formed using 12 coins of 10 rupees and 1 coin of 1 rupees.

// Constraints:
// 1 ≤ n ≤ 106

class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int>d ={1,2,5,10};
        int cnt =0, j=3;
        while(n){
            cnt+= n/d[j];
            n-= (n/d[j])*d[j];
            j--;
        }
        return cnt;
    }
};