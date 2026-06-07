class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>>pq;
    int n = nums.size();
    int maxa= -1e9;
    pq.push({0, n});
    for(int i =0; i<n; i++){
        int x = nums[i];
        int ma =0;
        while(!pq.empty() && pq.top().second < i - k)pq.pop();
            if(!pq.empty()) {
                ma = pq.top().first;
            }
        x += ma;
        pq.push({x, i});
        maxa = max(maxa, x );
    }
    return maxa;
    }
};