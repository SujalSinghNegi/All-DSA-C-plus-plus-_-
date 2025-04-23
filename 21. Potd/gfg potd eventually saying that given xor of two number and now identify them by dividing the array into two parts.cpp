class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int res =0;
        int n = arr.size();
        for(auto it:arr){
        res^=it;
       }
     
    //   int bit =0;
    //   while(res>0){
    //       if(res&1) break;
    //       bit++;
    //       res>>=1;
    //   }
    //   bit = 1<<bit;
    
    int bit = res & -res;  // shortcut to find the rightmost active bit
    
     //  cout<<bit<<endl;
       
       // bit is the no. which have the first bit on 
       int set1= 0, set2=0;
       for(int i=0;i<n; i++){
           int it = arr[i];
           if(it&bit)set1^=it;
           else set2^=it;
       }
       vector<int>ans= {set1, set2};
       sort(ans.begin(), ans.end());
       return ans;
    }
};
