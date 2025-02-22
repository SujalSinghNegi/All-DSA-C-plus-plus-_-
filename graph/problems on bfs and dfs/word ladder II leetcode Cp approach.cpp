class Solution {
    unordered_map<string,int>mpp;
     vector<vector<string>>ans;
     string b;
    private:
    void dfs(vector<string>&sq){
        if(sq.back()==b){
            reverse(sq.begin(), sq.end());
            ans.push_back(sq);
            reverse(sq.begin(), sq.end());
            return;
        }
        string word= sq.back();
            int level= mpp[word];
         for(int i=0; i<word.size(); i++){
                char original= word[i];
                for(char ch='a';  ch<='z'; ch++){
                    word[i]=ch;
                   if(mpp.find(word) != mpp.end() && mpp[word]==level-1){
                    sq.push_back(word);
                    dfs(sq);
                    sq.pop_back();
                   }
                }
                word[i]=original;
            }
    }
public:    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b= beginWord;
       unordered_set<string>st(wordList.begin(), wordList.end());
       queue<string>q;
        q.push(beginWord);
        mpp[beginWord]=0;
        st.erase(beginWord);
        while(!q.empty()){
            string word= q.front();
            q.pop();
            int level= mpp[word];
            if(word==endWord) break;
            for(int i=0; i<word.size(); i++){
                char original= word[i];
                for(char ch='a';  ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!= st.end()){
                        q.push(word);   
                        mpp[word]=level+1;
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        vector<string>sq;
        sq.push_back(endWord);
        dfs(sq);
        return ans;

    }
};