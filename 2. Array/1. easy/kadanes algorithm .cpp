class Solution {
  public:
   int maxSubarraySum(vector<int> &arr) {
        int count=INT_MIN,sum=0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            count=max(count,sum);
            if(sum<0)
            sum=0;
        }
        return count;
    }
};