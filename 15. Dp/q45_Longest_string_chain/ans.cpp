class Solution {
public:
static bool comp(string &a, string &b){
    return a.size() < b.size();
}
    int longestStrChain(vector<string>& words) {
        int  n = words.size();
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int>chains;
        int ans=  0;
       for(string word: words){
        chains[word] = 1;
        for(int i =0; i<word.size(); i++){
            string pre = word.substr(0, i) + word.substr(i+1);
            if(chains.find(pre) != chains.end()){
                chains[word] = max(chains[pre] +1  , chains[word]);
            }
            ans = max(ans, chains[word]);
        }
       }
        return ans;
    }
};