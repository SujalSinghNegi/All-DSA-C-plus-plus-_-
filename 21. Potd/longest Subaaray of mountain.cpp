

class Solution {
private :
    bool isMountain (int a , int b , int c){
        return b > a && b > c ;
    }
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;

        for(int i = 1 ; i < n-1 ; i++){
    
            if(isMountain(arr[i-1] , arr[i] , arr[i+1])){
                int l = i  - 1 ; 
                int r = i  + 1; 
                while(l > 0 && arr[l] > arr[l-1])
                    --l;
                while(r < n-1 && arr[r] > arr[r+1])
                    r++;
                mx = max(mx , r - l + 1 );
            }

        }

        return mx;
        
    }
};