class Solution {
public:
//we will have two option , to choose bw "(" and ")", 
// if the open are lesser than n , then add "(", and do recursively and
// if the close are lesser than open , then add ")" do it also recursively
    void solve(vector<string>&ans, string s, int o, int c, int n){
        if(o ==n && c==n){
            ans.push_back(s);
            return;
        }
     if(o<n)solve(ans, s+"(", o+1, c, n);
     if(c<o) solve(ans, s+")", o, c+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        solve(ans, "", 0,0,n);
        return ans;
    }
};