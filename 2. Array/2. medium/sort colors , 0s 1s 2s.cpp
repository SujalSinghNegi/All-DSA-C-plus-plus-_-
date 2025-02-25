// sort colors , 0s 1s 2s
//standard approach

        void sortColors(vector<int>& arr) {
            int n= arr.size();
            int low= 0;
            int mid= 0;
            int high= n-1;
            while(mid<=high){
                if(arr[mid]==0){
                    swap(arr[mid],arr[low]);
                    low++;
                    mid++;
                }
                else if(arr[mid]==1){
                    mid++;
                }
                else if(arr[mid]==2){
                    swap(arr[mid],arr[high]);
                    high--;
                }
            }
        }


        // normal approach , eqivalent to above
        void sortColors(vector<int>& nums) {
            int z=0, one=0, two=0;
            int n= nums.size();
            for(int i=0; i<n; i++){
                if(nums[i]==0)z++;
               else if(nums[i]==1)one++;
                else two++;
            }
            int i=0;
            for(int j=0; j<z; j++)nums[i++]=0;
            for(int j=0; j<one; j++)nums[i++]=1;
            for(int j=0; j<two; j++)nums[i++]=2;
    
    
        }