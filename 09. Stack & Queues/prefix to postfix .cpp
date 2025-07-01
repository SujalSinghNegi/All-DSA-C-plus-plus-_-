class Solution {
  public:
    bool isOp(char ch){
      if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='%' || ch=='^' ){
          return 1;
      }
      return 0;
  }
    string preToPost(string s) {
        int n = s.size();
        stack<string>st;
        for(int i=n-1; i>=0 ; i--){
            if(isOp(s[i])){
                string one = st.top();
                st.pop();
                string two = st.top();
                st.pop();
                st.push(one + two + s[i]);
            }else{
                string d(1, s[i]);
                st.push(d);
            }
        }
        return st.top();
        
        
    }
};