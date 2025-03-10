// Editorial
// To find the MEX of all possible values obtained by taking Bitwise OR of every possible subsequence of the array, lets go through some observations:

// MEX of all possible OR values can never be 0 as an empty subsequence can always have OR = 0.
// If 1 is missing in array, then MEX of all OR values will always be 1, as no subsequence can have OR value = 1 if 1 is not present in it.
// Similarly, if 2 is missing in array, then MEX of all OR values will always be 2, as no subsequence can have OR value = 2, if 2 is not present in it.
// If 1 and 2 are present in the array, then 3 can never be the MEX as {1, 2} has OR = 3.
// If 4 is missing in array, then MEX of all OR values will always be 4, as no subsequence can have OR value = 4 if 4 is not present in it.
// If 1, 2 and 4 are present in the array, then 5, 6 and 7 can never be the MEX as {1, 4}, {2, 4}, {1, 2, 4} have OR values as 5, 6 and 7 respectively.
// Using the above observations, we can say that if we start from 1, we only need to check those numbers which have only 1 set bit, that is numbers which are powers of 2, say (2^i) as all numbers from (2^i + 1) to (2^(i + 1) - 1) can be formed using the numbers from 1 to 2^i.
class Solution {
    public:
      int findMEX(vector<int>& arr) {
          int n = arr.size();
          unordered_map<int, int> m;
          for (auto& it : arr) {
              m[it]++;
          }
          int val = 1;
          int ans = 0;
          while (1) {
              if (!m.count(val)) {
                  ans = val;
                  break;
              }
              val *= 2;
          }
          return ans;
      }
  };