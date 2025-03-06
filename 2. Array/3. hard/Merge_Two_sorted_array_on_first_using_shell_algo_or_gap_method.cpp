class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // here the size of the nums1 is m+n, but the element inside are m, and the size of num2 is n, 
        // so i am using the gap method in the nums1, so for doing that, 
    // i firstly include all the elements of nums2 in the nums1
// like if nums1= [1,2,3,0,0,0] and nums2=[2,5,6] then after including the elements of nums2 in nums1, nums1=[1,2,3,2,5,6]
// now after the gap method nums1=[1,2,2,3,5,6]

        int gap= (m+n+1)/2;
        int l= 0, r= gap;
        int j=0;
        while(j<n){
           nums1[j+m]=nums2[j];
           j++;
        }

        // now the loop ends when the gap is 1 


        while(true){
            if(r==m+n){
                if(gap==1)break;
                gap= (gap+1)/2;
                l=0;
                r=gap;
            }

    // swapping the elements
            if(nums1[l]> nums1[r]){
                swap(nums1[l], nums1[r]);
            }
            l++;
            r++;
        }    
    }
};