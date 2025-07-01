class Solution {
  public:
  bool isOp(char ch){
      if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='%' || ch=='^' ){
          return 1;
      }
      return 0;
  }
    string preToInfix(string s) {
        int n = s.size();
        stack<string>st;
        
        for(int i=n-1; i>=0; i--){
            if(isOp(s[i])){
                string one = st.top();
                st.pop();
                string two = st.top();
                st.pop();
                st.push( "(" + one + s[i] + two + ")" );
        }else{
            string three(1, s[i]);
            st.push(three);}
        }
        return st.top();
    }
};