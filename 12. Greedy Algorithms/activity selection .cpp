// Activity Selection
// Difficulty: MediumAccuracy: 36.21%Submissions: 182K+Points: 4Average Time: 20m

// You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

// Examples:

// Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}

// Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
// Output: 1
// Explanation: A person can perform at most one activity.

// Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
// Output: 3
// Explanation: A person can perform activities 0, 1 and 3.

// Constraints:
// 1 ≤ start.size() = finish.size() ≤ 2*105
// 0 ≤ start[i] ≤ finish[i] ≤ 109

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>>v(n);
        for(int i=0; i<n; i++){
            v[i]= {start[i], finish[i]};
        }
        sort(v.begin(), v.end(), [](pair<int,int>&a , pair<int,int>&b){
            return a.second < b.second;
        });
        int pre = 0, cnt  =0;
        for(int i=0 ;i<n;i++){
            if(v[i].first > pre){
                cnt++;
                pre= v[i].second;
            }
        }
        return cnt;
    }
};