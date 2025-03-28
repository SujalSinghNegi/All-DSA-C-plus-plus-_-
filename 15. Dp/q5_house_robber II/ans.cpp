class Solution {
    public:
        int rob(vector<int>& arr) {
            int n = arr.size();
            if(n==1) return arr[0];
            int next1 =0, next2=0, maxa=0;
            for(int i= n-2; i>=0; i--){
                int curi= max(next1, next2+arr[i]);
                next2=next1;
                next1= curi;
            }
            maxa = next1;
            next1=0, next2=0;
             for(int i= n-1; i>=1; i--){
                int curi= max(next1, next2+arr[i]);
                next2=next1;
                next1= curi;
            }
            return max(maxa, next1);
        }
    };