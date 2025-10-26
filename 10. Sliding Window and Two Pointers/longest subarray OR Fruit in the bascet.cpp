// Longest subarray with Atmost two distinct integers
// Difficulty: MediumAccuracy: 47.98%Submissions: 130K+Points: 4Average Time: 30m

// Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.

// Examples:

// Input: arr[] = [2, 1, 2]
// Output: 3
// Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.

// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5
// Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105


class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int f1=0, f2=0, e1=0, e2=0, n=arr.size(), i=0, j=0, ans =0;
        while(i<n){
    if(e1==0 || arr[i] == e1){e1 = arr[i]; 
            f1++;
            }
            else if(e2==0 || arr[i]==e2){
                e2= arr[i];
                f2++;
            }else{
                while((f1!=0 && f2!=0)){
                    if(arr[j]==e1)f1--;
                    else if(arr[j]==e2)f2--;
                    j++;
                }
                if(f1==0)e1= arr[i], f1++;
                else if(f2==0)e2=arr[i], f2++;
            }
            ans= max({ans, f1+ f2});
            i++;
        }
        return ans;
    }
};


// same as above using map 

int totalElements(vector<int>& arr) {
    map<int, int> mp;  
    int i = 0, j = 0, n = arr.size();
    int size = 0;
    while (j < n) {
        mp[arr[j]]++;
        while (mp.size() > 2) {
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            i++;  
        }
        size = max(size, j - i + 1);
        
        j++;  
    }
    return size;
}