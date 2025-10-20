// 678. Valid Parenthesis String
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

//     Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//     Any right parenthesis ')' must have a corresponding left parenthesis '('.
//     Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//     '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:

// Input: s = "()"
// Output: true

// Example 2:

// Input: s = "(*)"
// Output: true

// Example 3:

// Input: s = "(*))"
// Output: true

 

// Constraints:

//     1 <= s.length <= 100
//     s[i] is '(', ')' or '*'.

class Solution {
public:
    bool checkValidString(string s) {
       int mini =  0, maxa =0;
            int n = s.size();
        for(int i=0; i<n; i++){
                if(s[i]=='(')mini++, maxa++;
                else if(s[i]==')')mini--, maxa--;
                else mini--, maxa++;

                if(mini<0)mini=0;
             if(maxa<0)return 0;
        }
        return mini==0;
    }
};