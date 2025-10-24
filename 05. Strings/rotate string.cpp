// 796. Rotate String
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

//     For example, if s = "abcde", then it will be "bcdea" after one shift.

 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

 

// Constraints:

//     1 <= s.length, goal.length <= 100
//     s and goal consist of lowercase English letters.

class Solution {
public:
    bool rotateString(string s, string goal) {
        int j = 0, N = s.size(), cnt =0, M= goal.size();
    if(N!=M) return 0;

       string a = s+s;
       return a.find(goal) < N+N;
    }
};