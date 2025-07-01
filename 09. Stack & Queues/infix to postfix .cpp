class Solution {
public:
int pt(char ch){
    if(ch=='^') return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-')return 1;
    else return -1;

}
    string infixToPostfix(string &s) {
        // Your code goes here
        int n = s.size();
        string ans;
        stack<int>st;
       for(int i=0; i<n; i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z' ) || (s[i]>='0' && s[i]<='9' )){
            ans+= s[i];
        }else if(s[i]=='(') st.push('(');
        else if (s[i]==')'){
            while(!st.empty() && st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && pt(s[i]) <= pt(st.top()) ){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
       }
       while(!st.empty()){
        ans+= st.top();
        st.pop();
       }
       return ans;
    }
};