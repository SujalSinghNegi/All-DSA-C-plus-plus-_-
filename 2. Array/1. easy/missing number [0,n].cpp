
/* 
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.*/  

// normal approach

// int missingNumber(int* nums, int numsSize) {
//     int sum = (numsSize * (numsSize + 1)) / 2;
//     for (int i = 0; i < numsSize; i++) {
//         sum -= nums[i];
//     }
//     return sum;
// }

// xor solution , more advance
class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int res=0, res1=0;
    for(auto& i:nums)res ^=i;
    for(int i=0; i<=nums.size();i++)res1 ^= i;    
    return res^res1;
    }
};