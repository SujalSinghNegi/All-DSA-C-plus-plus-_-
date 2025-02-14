class Solution{
    public:
    void generate(vector<string>&ans, string &s, int ind, int n){
        if(ind ==n){
            ans.push_back(s);
            return;
        }
             generate(ans, s, ind+1, n);
            s[ind]='1';
            if(ind==0 || (s[ind-1]!='1')) generate(ans, s, ind+1, n);
            s[ind]='0';
    }
        vector<string> generateBinaryStrings(int num){
            vector<string>ans;
            string s(num,'0');
            generate(ans, s, 0, num);
            return ans;
        }
    };