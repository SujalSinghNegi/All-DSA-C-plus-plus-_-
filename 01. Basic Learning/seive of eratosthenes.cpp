class Solution
{
public:
    vector<int>isPrime;
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here 
        isPrime.resize(N+1, 1);
        isPrime[0]=isPrime[1]=0;
        for(int i=2; i*i<N+1; i++){
             if(isPrime[i]){
            for(int j=i*i; j<N+1; j+=i){
               isPrime[j]=0;
            }
        }
        }
        vector<int>primeNumbers;
        for(int i=0;i<N+1; i++){
            if(isPrime[i]){
                primeNumbers.push_back(i);
            }
        }
        return primeNumbers;
    }
};
