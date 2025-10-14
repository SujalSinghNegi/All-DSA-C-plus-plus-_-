// Two odd Occuring
// Difficulty: MediumAccuracy: 49.49%Submissions: 83K+Points: 4

// Given an unsorted array, arr[] of positive numbers that contains even number of occurrences for all numbers except two numbers. Return that two numbers in decreasing order which has odd occurrences.

// Examples:

// Input: arr = [4, 2, 4, 5, 2, 3, 3, 1]
// Output: [5, 1] 
// Explanation: 5 and 1 have odd occurrences.

// Input: arr[] = [1, 7, 5, 7, 5, 4, 7, 4]
// Output: [7, 1]
// Explanation: 7 and 1 have odd occurrences.

// Constraints:
// 2 ≤ arr.size() ≤ 106
// 1 ≤ arr[i]≤ 107

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int num = 0;
        for(int x:arr) num^=x; //  the xor of two unique no . as other cancelled out
        int temp = num&(-num);  //  get the rightmost set bit , because in xor , 0s are the same bit, and the 1's are the different bit, we can get any diff bit, but we choose the rightmost, 
        int first =0, second =0;  // partition the array in two portion , one have that bit on and other that have that bit, off, 
        for(int x:arr){
           if(temp&x) first^=x;  
           else second^=x;
        }
        if(first<second)swap(first,second); // return these two no. in desecending order.
        return {first, second};
        
    }
};