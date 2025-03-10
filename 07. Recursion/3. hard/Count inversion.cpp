class Solution {
    public:
    void merge(vector<int>&arr, int low, int mid, int high, int &cnt){
        vector<int>t1(mid-low+1);
        vector<int>t2(high-mid);
        int n1= t1.size();
        int n2= t2.size();
        for (int i = 0; i < n1; i++) {
              t1[i] = arr[low + i];
          }
          for (int i = 0; i < n2; i++) {
              t2[i] = arr[mid + 1 + i];
          }
          int i = 0, j = 0, k = low;
          while (i < n1 && j < n2) {
              if (t1[i] <= t2[j]) {
                  arr[k++] = t1[i++];
              } else {
                  arr[k++] = t2[j++];
                  cnt += n1 - i; 
              }
          }
         while (i < n1) {
              arr[k++] = t1[i++];
          }
          while (j < n2) {
              arr[k++] = t2[j++];
          }
      }
      void mergeS(vector<int>&arr, int low, int high, int &cnt){
          if(low<high){
              int mid= (low+high)/2;
               mergeS(arr, low, mid, cnt);
              mergeS(arr, mid+1, high, cnt);
              merge(arr, low, mid, high, cnt);
          }
      }
     
      int inversionCount(vector<int> &arr) {
          int cnt=0;
          mergeS(arr, 0, arr.size()-1, cnt);
          return cnt; 
      }
  };
  