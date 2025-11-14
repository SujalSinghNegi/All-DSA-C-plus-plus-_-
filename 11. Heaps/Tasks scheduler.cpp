class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto it: tasks) freq[it - 'A']++;
        int m = *max_element(freq.begin(), freq.end());
        int parts = (m-1) * (n+1); // this is for the total - 1 parts, that we require at least, this much for characters that are less than, m, for mantaining the level of n+1 , and also the maximum element will occupy the last cell
        int d= 0;
// how many more elments are occupying the last part , these are the those who have the same freq as the highest in the array, so thy are also in the last cell and no other becauase have enough space in the initials cells
        for(auto it: freq) if(m == it) d++;
        return max(parts + d, (int)tasks.size());
    }
};