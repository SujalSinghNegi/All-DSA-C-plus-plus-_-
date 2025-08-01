class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n), pse(n);
        stack<int>st;
        int maxa = 0;
        for(int i=0; i<n; i++){
            while(!st.empty()  && arr[st.top()] > arr[i]){
                int ind = st.top(); 
                st.pop();
                nse[ind]= i;
                pse[ind]= (st.empty() ? -1 :st.top());
                maxa = max(maxa, arr[ind] * (nse[ind]- pse[ind]-1));
            }
            st.push(i);
        }
         while(!st.empty() ){
                int ind = st.top(); 
                st.pop();
                nse[ind]= n;       
                pse[ind]= (st.empty() ? -1 :st.top());
                maxa = max(maxa, arr[ind] * (nse[ind]- pse[ind]-1));
            }

        return maxa;
    }
};