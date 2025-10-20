// Fractional Knapsack
// Difficulty: MediumAccuracy: 32.46%Submissions: 365K+Points: 4Average Time: 20m

// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

// Input: val[] = [500], wt[] = [30], capacity = 10
// Output: 166.670000
// Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.

// Constraints:
// 1 ≤ val.size = wt.size ≤ 105
// 1 ≤ capacity ≤ 109
// 1 ≤ val[i], wt[i] ≤ 104

class Solution {
  public:
//   static bool comp(pair<int,int>&a, pair<int,int>&b){
//       double f = double(a.first)/ double(a.second);
//       double s = double(b.first)/ double(b.second);
//       return f>s;
//   }
  static bool comp(pair<int,int>&a, pair<int,int>&b){
    // Cast to long long to prevent overflow during multiplication
    return (long long)a.first * b.second > (long long)b.first * a.second;
}
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        // sort the array according to the val[i]/wt[i]
            int n= val.size();
        vector<pair<int,int>>v(n);
        for(int i=0; i<n; i++){
            v[i]= {val[i], wt[i]};
        }
        sort(v.begin(), v.end(), comp);
        double sum =0;
        for(int i=0; i<n; i++){
            if(capacity >= v[i].second){
                sum+= 1.0 * v[i].first ;
            }else{
                sum += ((1.0* v[i].first ) / v[i].second)*capacity;
           break;
            }
            capacity -= v[i].second;
        }
        return sum;
    }
};