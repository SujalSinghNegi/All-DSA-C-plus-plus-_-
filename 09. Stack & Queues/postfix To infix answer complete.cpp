class Solution {
public:
bool isDigit(string s){
    if(s.size()==1){
        char ch = s[0];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ) return 0;
    }
    return 1;
}
int get (int one, int two, char ch){
       switch (ch){
        case '+':
        return one + two;
        case '-':
        return one - two;
        case '*':
        return one * two;
        case '/':
        return one / two;
       }
       return 0;
}
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        for(int i =0; i<n; i++){
            if(isDigit(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                st.push( get(two, one, tokens[i][0]));
            }
        }
        return st.top();
    }
};