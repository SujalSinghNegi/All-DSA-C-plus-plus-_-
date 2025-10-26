
// 424. Longest Repeating Character Replacement
// Solved
// Medium
// Topics
// premium lock iconCompanies

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

 

// Constraints:

//     1 <= s.length <= 105
//     s consists of only uppercase English letters.
//     0 <= k <= s.length






class Solution {
public:
    int characterReplacement(string s, int k) {
        int i =0, j =0, n =s.size(), ans=0, maxf=0;
        unordered_map<int,int>mpp;
        while(i<n){
            mpp[s[i]]++;
            maxf = max(mpp[s[i]], maxf);
           while(maxf + k < i-j+1 ){
            mpp[s[j]]--;
            if(mpp[s[j]]==0)mpp.erase(s[j]);
            j++;
           }

        ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};





class Solution {
public:
    int characterReplacement(string s, int k) {
         int n=s.length();
        int l=0;
        int r=0;
        int maxf=0;
        int mx=0; 
       vector<int> count(26, 0);
        for(;r<n;r++){
            count[s[r] - 'A']++;
             maxf = max(maxf, count[s[r] - 'A']);  
             if ((r - l + 1) - maxf > k) { // we can use if instead of while only because we already have the window of size , r-l+1, so we want greater than that, so if there exist a valid answer that must be greater than it  , no sense of calculating the valid answer that is less than that size, thats why keep that window size as there may not be the valid window currently , but we are searching for somthing bigger
                count[s[l] - 'A']--;
                l++;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};