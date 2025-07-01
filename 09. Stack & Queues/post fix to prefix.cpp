class Solution {
  public:
    bool isOp(char ch){
      if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='%' || ch=='^' ){
          return 1;
      }
      return 0;
  }
    string postToPre(string s) {
        // Write your code here
        stack<string>st;
        int n = s.size();
        for(int i =0; i<n; i++){
            if(isOp(s[i])){
                string one = st.top();
                st.pop();
                string two = st.top();
                st.pop();
                
                st.push(s[i] + two + one);
            }else{
                string d(1, s[i]);
                st.push(d);
            }
        }
        return st.top();
    }
};