class Solution {
public:
int ans=0;
void merge(vector<int>&nums, int low, int mid, int high){
    vector<int>temp;
int i=low, i1=low, j= mid+1, j1= mid+1;
int cnt=0;
// count pairs code
 while(i1<=mid && j1<=high){
        if((long long)nums[i1] > 2 * (long long)nums[j1]){
            cnt+=mid-i1+1;
            j1++;
        }else{
            i1++;
        }
    }
    ans+=cnt;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid)temp.push_back(nums[i++]);
    while(j<=high)temp.push_back(nums[j++]);
    int k=0;
    for(int ind= low; ind<=high; ind++){
        nums[ind]= temp[k++];    
    }
}
void mergesort(vector<int>&nums, int low,int high){
    if(low<high){
    int mid = (low + high)/2;
    mergesort(nums, low, mid );
    mergesort(nums,  mid+1, high);
    merge(nums, low, mid, high);
    }
    }
 int reversePairs(vector<int>& nums) {
        int n= nums.size();
        mergesort(nums, 0, n-1);
        return ans;
    }
};
