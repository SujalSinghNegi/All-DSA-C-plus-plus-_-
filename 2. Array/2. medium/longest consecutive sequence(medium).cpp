      /* brute force solution-> 
    count the consecutive array have the diff 1, if not then reset the counter , then max count will be the ans;
*/

class Solution {
  public:
         int longestConsecutive(vector<int>& nums) {
         unordered_set<int> s(nums.begin(), nums.end());
          int maxa =0;
          for(auto it:s){
              if(s.find(it-1)==s.end()){
                  int cnt=1;
                  while(s.find(it+cnt)!=s.end()){
                      cnt++;          
                  }
                  maxa = max(cnt, maxa);
              }
          }
          return maxa;
      }
  
  };


  // my approach
  class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
           /* brute force solution-> 
        count the consecutive array have the diff 1, if not then reset the counter , then max count will be the ans;
    
    
    
    */
    unordered_map<int,int>mpp;
    for(auto it: nums){
        mpp[it]=1;
    }
    int maxa=0;
    for(auto it:nums){
        int cnt=1;
        int b=it;
        if(mpp[b]>1)continue;
        while(mpp[b+1]){
            if(mpp[b+1] >1 ){
                cnt+=mpp[b+1];
                break;
            }
            cnt++;
            b++;
            mpp[b]=cnt;
        }
        mpp[it]=cnt;
        maxa=max(cnt, maxa);
    }
    return maxa;
        }
    };