//union of two sorted array with dublicate.cpp 
class Solution {
    public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          // return vector with correct order of elements
          int i=0, j=0;
          int n= a.size(), m= b.size();
          vector<int>_union;
          while(i<n && j<m){
              while(i<n-1 && a[i]==a[i+1])i++;
              while(j<m-1 && b[j]==b[j+1])j++;
              if(a[i]<=b[j]){
                  if(a[i]==b[j])j++;
                  _union.push_back(a[i++]);
              }else{
                  _union.push_back(b[j++]);
              }
          }
          while(i<n){
              while(i<n-1 && a[i]==a[i+1])i++;
               _union.push_back(a[i++]);
          }
          while(j<m){
               while(j<m-1 && b[j]==b[j+1])j++;
                _union.push_back(b[j++]);
               
          }
          return _union;
      }
  };