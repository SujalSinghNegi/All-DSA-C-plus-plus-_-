class Solution {
public:
    int trap(vector<int>& height) {
        // max hegiht at abs(left - right), 
        int n = height.size();
        vector<int>left(n), right(n);
        int li=0, ri=0;
        for(int i=0; i<n; i++){
            li= max(li, height[i]);
            ri = max(ri, height[n-1-i]);
            left[i]=li;
            right[n-1-i]= ri;
        }
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int a = min(left[i-1], right[i+1])-height[i];
            if(a>0)ans+= a;
        }
        return ans;
    }

};