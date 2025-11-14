
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        sort(hand.begin(),hand.end());
        int n = hand.size();
        if ( groupSize == 1) return 1;
        if ( n % groupSize != 0) return 0;
        for(int i = 0; i<n;i++){
            if(pq.empty() || pq.top().first == hand[i])pq.push({hand[i], 1});
            else if( pq.top().first == hand[i] - 1){
                pair<int,int>it = {hand[i], pq.top().second + 1};
                pq.pop();
               if(it.second != groupSize) pq.push(it);
            }
            else return 0;
        }
       
       
        return pq.empty();
    }
};