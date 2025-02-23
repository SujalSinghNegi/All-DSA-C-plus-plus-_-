class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       // queue for storing the word that are found, with their no. of level we found them from source
    
       // for each element in a queue apply the all posible character from starting letter to end letter, by a to z, if found then put in a queue and pop it form set 
       // yes also make a set of all the word possible so it is easy to check in a set rather than a vector
        unordered_set<string>s;
       for(auto it:wordList)s.insert(it);
       queue<pair<string,int>>q;
       q.push({beginWord,1});
       s.erase(beginWord);
       while(!q.empty()){
            auto it= q.front();
            q.pop();
            string check= it.first;
            int level= it.second;
            for(int i=0; i<check.size(); i++){
                char original = check[i];// save the original word, because after the altering the ith character of the string , the original char should be same and then check for the another word
                for(int j=0; j<26; j++){
                    check[i]=j+'a';
                    if(s.find(check)!=s.end()){
                        s.erase(check);
                        q.push({check,level+1});
                        if(check==endWord)return level+1;
                    }

                }
                check[i]=original;
            }
       }
        return 0;
    }
};