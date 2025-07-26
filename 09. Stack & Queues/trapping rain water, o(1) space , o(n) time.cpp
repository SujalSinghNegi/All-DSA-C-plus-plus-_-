class Solution {
public:
    int trap(vector<int>& arr) {
    int n = arr.size();
       int l =0, r= n-1; 
       int lMax=0, rMax = 0, sum=0;
       while(l<r){
        if(arr[l]<= arr[r]){
            if(lMax > arr[l])sum+= lMax-arr[l];
            else lMax = arr[l];
            l++;
        }else{
            if(rMax > arr[r])sum+= rMax - arr[r];
            else rMax = arr[r];
            r--;
        }
       }
       return sum;
    }
};