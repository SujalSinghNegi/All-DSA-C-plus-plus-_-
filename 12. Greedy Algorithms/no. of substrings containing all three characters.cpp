// 1358. Number of Substrings Containing All Three Characters
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

// Example 3:

// Input: s = "abc"
// Output: 1

 

// Constraints:

//     3 <= s.length <= 5 x 10^4
//     s only consists of a, b or c characters.





class Solution {
public:
    int numberOfSubstrings(string s) {
        // 1 + 2 
        map<int,int>mpp;
        int n = s.size(), j=0, cnt =0;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
            if(mpp.size()<3)continue;
            while(j<i ){
                mpp[s[j]]--;
                if(mpp[s[j]]==0){
                    mpp[s[j]]=1;
                    break;
                }
                j++;
            }
            cnt+= j+1;

        }
        return cnt;
    }
};


//--------


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans =0;
    vector<int> pos{-1, -1, -1};
    for(int i = 0; i<n; i++){
        pos[s[i]-'a']=i;
        ans += 1+ min({pos[0], pos[1], pos[2]});
    }
    return ans;
    }
};