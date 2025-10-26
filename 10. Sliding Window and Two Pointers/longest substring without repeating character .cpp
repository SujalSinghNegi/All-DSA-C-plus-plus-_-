
// 3. Longest Substring Without Repeating Characters
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given a string s, find the length of the longest

// without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0};
        int j = 0, cnt = 0, maxa = 0, n = s.size();
        for(int i =0; i<n; i++){
            freq[s[i]]++;
            if(freq[s[i]]!=1)
            {
                while(j<=i && freq[s[i]]!=1){
                    freq[s[j]]--;
                    j++;
                }
            }
            maxa = max(i-j+1, maxa);
        }
        return maxa;
    }
};