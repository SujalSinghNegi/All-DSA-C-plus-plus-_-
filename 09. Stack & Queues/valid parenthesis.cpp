class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n & 1)
            return 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int a = s[i];
            if (a == '(' || a == '{' || a == '[') {
                st.push(a);
            } else {
                if (!st.empty()) {
                    int b = st.top();
                    if ((b == '(' && a == ')') ||                       
                   (b == '{' && a == '}') ||                        
                    (b == '[' && a == ']')
                      ) st.pop();
                        else return 0;

                } else
                    return 0;
            }
        }
        return st.empty();
    }
};