/*

Using Properties of Bitwise XOR
The task is to find the number of pairs (i, j) such that arr[i] ^ arr[j] = i ^ j. Let's first simplify the expression arr[i] ^ arr[j] = i ^ j:

arr[i] ^ arr[j] = i ^ j
arr[i] ^ arr[j] ^ i = i ^ j ^ i (Bitwise XOR with i on both the sides)
arr[i] ^ arr[j] ^ i = j
arr[i] ^ arr[j] ^ i ^ arr[j] = j ^ arr[j] (Bitwise XOR with arr[j] on both sides)
arr[i] ^ i = arr[j] ^ j
So, the problem is reduced to finding the number of pairs (i, j) such that arr[i] ^ i = arr[j] ^ j. 
So, we can iterate over arr[] and for each index i, we find arr[i] ^ i,
and find how many elements arr[j] (j < i) have arr[j] ^ j = arr[i] ^ i.
This can be easily calculated using a hashmap storing the frequency of (arr[i] ^ i) for each index./*
*/

class Solution {
    public:
      long long xorPairs(vector<int>& arr) {
          int n = arr.size();
          map<int, int> mp;
          long long ans = 0;
          for (int i = 0; i < n; i++) {
              ans += mp[arr[i] ^ i];
              mp[arr[i] ^ i]++;
          }
          return ans;
      }
  };
  