/*
763. Partition Labels
Solved
Medium
Topics
Companies
Hint
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n= s.size();       
        int mpp[26]={0};
        for(int i=0; i<n; i++){
            mpp[s[i]-'a']=i;
        }
        int maxa=mpp[s[0]-'a'];
        vector<int>ans;
        int i=0;
        int x=0;
        for(;i<n; i++){
            if(i==maxa){
                if(ans.size()!=0)x+=ans.back();
                ans.push_back(i+1-x);
                if(i<n-1)maxa= mpp[s[i+1]-'a'];

            }
            maxa= max(maxa, mpp[s[i]-'a']);
        }
        return ans;
    }
};