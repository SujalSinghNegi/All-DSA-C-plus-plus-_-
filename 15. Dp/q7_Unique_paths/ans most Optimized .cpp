class Solution {
public:
#define ll long long
    int uniquePaths(int m, int n) {
        /*
        To reach from start to end we have to move, left to right, and top to bottom  ,
        so if we move m -1 down and n-1 right dir, that is total of 
        m+n-2 dir, then we will reach to the destination.

        so the ans is  , (m+n-2)! / (m-1)! * (n-1)!
        or say select , m-1 boxes out of m+n-2 
        or say select , n-1 boxes out of m+n-2  

        res =(m)*(m+1)*(m+2)...*(m+n-2) / 1*2*...*(n-1)
        */
        ll res = 1;
        for(ll i=1; i<=n-1; i++){
            res=res*(m-1+i)/i;
        }
        return (int)res;
    }
};