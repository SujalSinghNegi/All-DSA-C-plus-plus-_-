class Solution {
    public:
        void nextPermutation(vector<int>& arr) {
              // Brute Solution-> generete all the permutation, then ans will be nextPremutaion of that next array of nums TC-  N!xN
            // better -> stl have the default stl library named
            //next_permutation(nums.begin(), nums.end());
    
            // best Solution->
            int n= arr.size(), minInd=n-1, maxInd=n-1;
           // 1 2 4 5 3 --5
            int maxa=arr[n-1];
            int i=n-1;
            for( ; i>=0; i--){
                if(arr[i]>=arr[maxInd]){
                    maxInd=i;
                }else break;
            }
            if(maxInd==0){
                reverse(arr.begin(), arr.end());
                return;
            }
            // 2 1 5 4 3 0 0 
           // int num = arr[maxInd-1];
            for(int j=n-1; j>=maxInd; j--){
                if(arr[j]>arr[maxInd-1]){
                        swap(arr[j], arr[maxInd-1]);
                        reverse(arr.begin()+maxInd, arr.end());
                        return;
                }
            }
        }
    };