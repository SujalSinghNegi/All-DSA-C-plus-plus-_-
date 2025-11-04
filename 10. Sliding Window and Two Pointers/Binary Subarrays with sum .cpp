// 930. Binary Subarrays With Sum
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

 

// Constraints:

//     1 <= nums.length <= 3 * 104
//     nums[i] is either 0 or 1.
//     0 <= goal <= nums.length


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0, j=0, curSum =0, left=0, ans=0, n=nums.size();
        while(i<n){
           if(nums[i]==1)left = 0; // if find any 1, then rest prevZeros
            curSum+=nums[i];
              while(j<i && curSum > goal){ // move j forward till curSum is > goal, 
              // also find the zeros , but reset it as well if find any one, 
                    if(nums[j]==0)left++;
                    else left =0;
                    curSum-= nums[j];
                    j++;

                }
            // after the above operations, if find the goal
            if(curSum == goal){
                // then move j forward if any zeros, are there, this will execute when there are only zeros, and that when above loop will not run and this will run, 
                while(j<i && nums[j]==0){
                    left++; // counts the zeros, 
                    j++;
                }
                ans += left+1 ; // add all the zeros +1, that, choose any or nothing,
                }
            
            i++;
        }    
        return ans;
    }
};


//  approach 2: caluculate no of subarrays with sum <= goal and sum <= goal-1 and take the difference


class Solution {
public:

int subarraysLessThanGoal(vector<int>&nums, int k){
    if(k<0) return 0;
    int i=0, j=0, n= nums.size(), cnt=0, sum=0;
    while(i<n){
        sum+= nums[i];
        while( sum > k){
            sum-= nums[j];
            j++;
        }
        cnt += i - j + 1;
        i++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return subarraysLessThanGoal(nums, k)- subarraysLessThanGoal(nums, k-1);
    }
};
