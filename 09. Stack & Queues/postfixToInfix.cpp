class Solution {
public:
bool isDigit(string s){
    if(s.size()==1){
        char ch = s[0];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ) return 0;
    }
    return 1;
}
    string postfixToInfix(vector<string>& tokens) {
        stack<string>st;
        int n = tokens.size();
        for(int i =0; i<n; i++){
            if(isDigit(tokens[i])){
                st.push(tokens[i]);
            }else{
                string one = st.top();
                st.pop();
                string two = st.top();
                st.pop();
                st.push( "(" + two + tokens[i]+ one + ")" );
            }
        }
        return st.top();
    
    }
};