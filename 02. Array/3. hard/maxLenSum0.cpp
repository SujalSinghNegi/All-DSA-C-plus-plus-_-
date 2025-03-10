
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int>mpp;
        int n= arr.size();
        int sum=0,maxa=0;
        mpp[0]=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==0){
                maxa= i+1;
            }
           else if(mpp.find(sum)!=mpp.end()){
                maxa= max(maxa, i-mpp[sum]);
            }
           if(mpp.find(sum)==mpp.end()) mpp[sum]=i;
        }
        return maxa;
    }
};
