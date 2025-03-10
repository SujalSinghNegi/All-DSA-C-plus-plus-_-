// Check the Prime no. or not

// normal and optimized code 
class Solution {
    public:
      bool isPrime(int n) {
          if(n<=1)return false;
          if(n==2) return 1;
          for(int i=2; i*i<= (n); i++){
              if(n%i==0) return 0;
          }
          return 1;
      }
  };



//slightly optimized and for long long number
bool isPrime(long long n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n <= 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Exclude multiples of 2 and 3

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}