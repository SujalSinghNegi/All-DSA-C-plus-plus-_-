// get the power of very large number
class Solution {
    public:
        long double power(long double a, long long b){
            if(b<0)b=-b;
            long double res=1;
            while(b>0){
                if(b&1){
                    res= res*a;
                }
                a= a*a;
                b=b>>1;
            }
            return res;
        }
        double myPow(double x, int n) {
          long double ans= power(x,n);
          if(n<0)ans= 1/ans;
          return ans;
    
        }
    };