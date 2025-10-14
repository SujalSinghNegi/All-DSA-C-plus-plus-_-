
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(const std::vector<T>& vec);

template <typename T>
void inputVector(std::vector<T>& vec, int n);

void yes();
void no();

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

// //---------------------------------------- start--------------------------------------------




void solve(){
    
   int n;  // ll  n;
   cin>>n;
  //  vi a(n);  // vll a(n); 
  //  inputVector(a,n); 
  PrimeTools p(n);
  cout<<"5 is prime or not : " << p.isPrime(5)<<endl;
  printVector(p.getPrimeFactors(20));
  printVector(p.getUniquePrimeFactors(20));
  printVector(p.primeNumbers);
  
   
   
}




// //-------------------------------------------end----------------------------------------------


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
       int t;
       cin >> t;

                 //     int t = 1;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
  

// //-----------------------------------------------------------------------------------------------   
    

// //-------------------------------------- IP OP vector ------------------------------------------
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void inputVector(std::vector<T>& vec, int n) {
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}
