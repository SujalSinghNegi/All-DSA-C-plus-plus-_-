class Solution {
    public:
    // it will check weather the string is palindrom or not
    bool checkPalindrom(string &s, int l, int r){
        while(l<r){
            if(s[l++]!=s[r--]) return 0;
        }
        return 1;
    }
    // this recursive func. will check for each index from left to right, 
    // first the left and right will be 0, and then loop goes from right to right=n-1
    // if the string from left to right is checkpalindrom from the above func. then make a partition at that index then , start the checking
    // again from the , right+1 , to right+1,  and this right+1 now go to n-1;

        void back(string &s, int l, int r, int n,vector<string>&ds, vector<vector<string>>&ans){
            if(r==n){
                ans.push_back(ds);
                return ;
                }
           for(int j=r; j<n; j++){ if(checkPalindrom(s, l, j)){
                ds.push_back({s.begin()+l, s.begin()+j+1});
                back(s, j+1, j+1, n, ds, ans);
                ds.pop_back();
                
                }}
           // back(s, l, r+1, n, ds, ans);
    
    
        }
        vector<vector<string>> partition(string s) {
            int n= s.size();
            vector<vector<string>>ans;
            vector<string>ds;
            back(s, 0,0,n,ds,ans);
            return ans;
        }
    };
    // A ROUGH PHOTO IS THERE WITH A RECURSION TREE OF THIS PROBLEM, WITH NAME OF "palindrom_partition.jpg"