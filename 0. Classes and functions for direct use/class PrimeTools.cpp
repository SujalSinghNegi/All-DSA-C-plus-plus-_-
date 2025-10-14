class PrimeTools { // intialise the spf of every no. and prime no. till n, in O(N.(log(log(N))))
public:
// function isPrime(x)  return true/false 
// data member primeNumbers give all primes till N
// function getprimeFactors(x) return list of the prime factors the no. is actually build with, 
// 20= { 2, 2, 5}
// function getUniquePrimeFactors(x) return list of the unique prime factors of the no. 
// 20 = {2,5}

    vector<int> spf;
    vector<int> primeNumbers;
   
    PrimeTools(int N) {
        spf.resize(N + 1);
        for (int i = 0; i <= N; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) { 
                        spf[j] = i;
                    }
                }
            }
        } 
        for (int i = 2; i <= N; i++) {
            if (spf[i] == i) {
                primeNumbers.push_back(i);
            }
        }
    }
  
    bool isPrime(int n) {
        if (n < 2) return false;
        return spf[n] == n;
    }
    vector<int> getPrimeFactors(int n) {
       vector<int> factors;
        while (n != 1) {
            factors.push_back(spf[n]);
            n = n / spf[n];
        }
        return factors;
    }
    vector<int> getUniquePrimeFactors(int n) {
        vector<int> factors;
        while (n != 1) {
            int current_prime = spf[n];
            factors.push_back(current_prime);
            while (n % current_prime == 0) {
                n = n / current_prime;
            }
        }
        return factors;
    }
};