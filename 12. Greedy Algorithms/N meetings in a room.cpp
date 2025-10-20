// N meetings in one room
// Difficulty: EasyAccuracy: 45.3%Submissions: 367K+Points: 2Average Time: 20m

// You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Examples :

// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

// Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
// Output: 1
// Explanation: Only one meetings can be held with given start and end timings.

// Input: start[] = [1, 2], end[] = [100, 99]
// Output: 1

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ start[i] < end[i] ≤ 106


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(pair<int,int>&a, pair<int,int>&b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>m(n);
        for(int i=0; i<n; i++)m[i]= {start[i], end[i]};
        sort(m.begin(), m.end());
        int st=-1, ed =-1 , cnt=0;
        for(int i=0; i<n; i++){
            auto [f, s]= m[i];
            if(f>ed){
                cnt++;
                st = f;
                ed = s;
            }else if(f>= st && s<= ed){
                st = f, ed = s;
            }
        }
        return cnt;
        
    }
};
