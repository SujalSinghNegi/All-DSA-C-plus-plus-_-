class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n =nums.size();
       int N = n/2;
       int total = accumulate(nums.begin(), nums.end(), 0);
       vector<vector<int>>left(N+1), right(N+1);
       for(int mask = 0; mask < (1<<N); mask++){
        int sz = 0, l = 0, r= 0;
            for(int i = 0; i<N; i++){
                if(mask & (1<<i)){
                    sz++;
                    l+=nums[i];
                    r+=nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
       }
       for(int sz = 0; sz<=N; sz++){
        sort(right[sz].begin(), right[sz].end());
       }

    int res = INT_MAX;
      for(int sz = 0; sz <= N; sz++){
            for(int &lsum: left[sz]){
            /* we want that rsum in corresponding to the lsum, 
            1-> whose size is N-sz, 
            2-> who added with lsum , => lsum + rsum, will lead to minimum of remaning - (lsum + rsum), => total - 2 * (lsum + rsum)

        => total - 2*lsum - 2*rsum
        let k = total - 2*lsum - 2*rsum, k should be minimum that is 0, 
        rsum = (total - 2*lsum - k)/2
        for k to be 0, rsum = (total - 2*lsum)/2, and for minimizing the k, rsum must be as close to  (total - 2*lsum)/2
*/
            int required = (total - 2 * lsum) / 2;
            auto it= lower_bound(right[N-sz].begin(), right[N-sz].end(), required);
// if the lower bound exist, that mean there is closest value that is >= required
// or say rsum[N-sz].back() is smaller than required
            if(it != right[N-sz].end()) res = min(res, abs(total - 2 * (lsum + (*it))));



// we can say that we are checking the both value that are smaller and bigger than required value for out best closest difference


// finding if the value exist just before it, is close to minimum diff, 
            if(it != right[N-sz].begin()) { // or can say, it != rsum[N-sz][0]
            auto itl = it;
            --itl;
            res = min(res, abs(total - 2 * (lsum + (*itl))));
        // checking this value is the first element in that size, so we cant check the previous element from that, 
            }
// dont think that we are not checking on that index, but if you carefully see these 2 if condition they are doing it well that we are accuratley checking that index if that exist , or other wise the next closest either left side or right side.

// as if the we found the exact match , 1st one does it no need to check other conditino, 
// if dont find that particular index , so we are just checking our iterator is in the begening or at the end. 
            }
      }
      return res;

    }
};