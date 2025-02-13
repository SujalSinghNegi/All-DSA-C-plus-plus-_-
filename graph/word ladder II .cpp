class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans; //  of all shortest sequence
        unordered_set<string>s(wordList.begin(), wordList.end()); 
        // queue of sequence, the next word will be according the last word
        vector<string>visited;
        queue<vector<string>>q;
        q.push({beginWord});
        int level=0;
        while(!q.empty()){
            vector<string>cur= q.front();
            q.pop();
            string word= cur.back();
           if(cur.size()>level){ 
               level++;
               for(auto it:visited)s.erase(it);}
            
            if(word== endWord){
                if(ans.size()==0)ans.push_back(cur);
                else if(ans[0].size()==cur.size())ans.push_back(cur);
            }
            for(int i=0; i<word.size(); i++){
                char original= word[i];
                for(int j=0; j<26; j++){
                    word[i]=j+'a';
                    if(s.find(word)!=s.end()){
                        cur.push_back(word);
                        q.push(cur);
                        visited.push_back(word);
                        cur.pop_back(); 
                    }
                    
                }
                word[i]= original;
            }
        }
        return ans;
    }
};
