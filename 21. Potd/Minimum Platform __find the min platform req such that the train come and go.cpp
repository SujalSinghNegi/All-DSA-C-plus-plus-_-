class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int mx=1;
        int cnt=0;
        int i=0,j=0;
        int n=arr.size(),m=dep.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        while(i<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};