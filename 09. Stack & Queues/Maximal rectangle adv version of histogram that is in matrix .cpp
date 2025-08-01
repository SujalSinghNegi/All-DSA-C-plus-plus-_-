class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
     int n = mat.size(), m = mat[0].size();
        vector<int>nse(m), pse(m);
        stack<int>st;
        int maxa = 0;
        vector<int>arr(m,0);
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]=='0')arr[j]=0;
            else arr[j]+=1;
            while(!st.empty()  && arr[st.top()] > arr[j]){
                int ind = st.top(); 
                st.pop();
                nse[ind]= j;
                pse[ind]= (st.empty() ? -1 :st.top());
                maxa = max(maxa, arr[ind] * (nse[ind]- pse[ind]-1));
            }
            st.push(j);
        }
         while(!st.empty() ){
                int ind = st.top(); 
                st.pop();
                nse[ind]= m;       
                pse[ind]= (st.empty() ? -1 :st.top());
                maxa = max(maxa, arr[ind] * (nse[ind]- pse[ind]-1));
            }
            
        }
    

        return maxa;
    
    }
};