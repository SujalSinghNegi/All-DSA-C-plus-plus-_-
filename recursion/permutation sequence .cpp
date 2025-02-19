class Solution {
public:
    string getPermutation(int n, int k) {
        // make array from 1 to n , then take the index as the algorith, and erase them, 
        vector<int>num;
        int fact=1; // factorial for n-1, because the total choices are n! 
        // n! have total n * (n-1) ! , that means we have (n-1)choices to choose the first numbers, then , n-2 choices for third num, and then n-3 choices..... so on
        for(int i=1; i<=n-1; i++){
            num.push_back(i);
            fact *= i;
        }
        num.push_back(n);
        k = k-1; //for 0-based indexing for k
        // example n = 4,  k = 16, then we have 4! total choices and 
        // 4 * 3! choices, for to choose to the first number we have to n choices = 4 choice.
     
        // k= k% fact <==> 16 % 4 =>  at k = 4
        string ans="";
        while(true){
               // k/fact <==>  16/4 = 2 , we have that number at 2nd index (and which is number 3 at 2nd index -> {1,2,3,4}, add 3 to the ans, and erase it from the num), 
            ans+= to_string(num[k/fact]);
            num.erase(num.begin()+ k/fact);
            // if the all element are earsed or say all element are added to ans, then break the loop.
            if(num.size()==0) break;
            //  now we have remaining the k - k/fact ,or say remainder, 
            // (k%fact)th permutation is the answer
            k= k%fact;
            fact /= num.size(); //  now we have the (n-2) choices to choose another num.
        }
        return ans;
    }
};