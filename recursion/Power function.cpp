// get the power of very large number
class Solution {
public:
    const int mod = 1000000007;
    long long power(long long a, long long b){
        long long res= 1;
        while(b>0){
            if(b&1){
                res= (res*a)%mod;
                
            }
            a=(a*a)%mod;
           b= b>>1;
        }
        return res%mod;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even= n-odd;
        
        long long ans = (power(4,odd) * power(5,even))%mod;
        return (int)ans;
    }
};