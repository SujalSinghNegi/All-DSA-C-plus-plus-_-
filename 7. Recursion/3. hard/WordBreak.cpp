class Solution {
    public:
        bool check(int ind, vector<string>& wordDict, int it, string &s, int m, int n) {
            if (n > m - ind) return false;
            for (int i = 0; i < n; i++) {
                if (s[ind + i] != wordDict[it][i]) return false;
            }
            return true;
        }
    
        bool back(int ind, vector<vector<int>>& mpp, string &s, int m, vector<string>& wordDict, vector<int>& dp) {
            if (ind == m) return true;  // Successfully reached the end
            if (dp[ind] != -1) return dp[ind];  // Return previously computed result
    
            int ch = s[ind] - 'a';
            for (auto it : mpp[ch]) {
                int n = wordDict[it].size();
                if (check(ind, wordDict, it, s, m, n)) {
                    if (back(ind + n, mpp, s, m, wordDict, dp)) {
                        return dp[ind] = true;
                    }
                }
            }
    
            return dp[ind] = false;  // Mark this index as not possible
        }
    
        bool wordBreak(string s, vector<string>& wordDict) {
            vector<vector<int>> mpp(26);
            int n = wordDict.size();
            for (int i = 0; i < n; i++) {
                mpp[wordDict[i][0] - 'a'].push_back(i);
            }
    
            int m = s.size();
            vector<int> dp(m, -1);  // Initialize dp array with -1 (unvisited)
    
            return back(0, mpp, s, m, wordDict, dp);
        }
    };
    