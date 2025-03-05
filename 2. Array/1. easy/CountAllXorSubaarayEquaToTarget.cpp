int Solution::solve(vector<int> &arr, int target) {
        int n= arr.size();
    unordered_map<int,int>mpp;
    int x=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        x^=arr[i];
        if(x==target)cnt++;
        if(mpp.find(x^target)!=mpp.end()){
            cnt+=mpp[x^target];
        }
        mpp[x]++; 
    }
    return cnt;
}
