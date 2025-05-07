// Stack class.
#include <bits/stdc++.h>
using namespace std;

class Stack {
    
public:
    int ind,max;
    vector<int>st;
    Stack(int capacity) {
        // Write your code here.
        ind =-1;
        max= capacity;
        st.resize(max);
    }

    void push(int num) {
        // Write your code here.
        if(max>ind+1){
            st[++ind]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(ind>=0){
            return st[ind--];
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(ind>=0){
            return st[ind];
        }
        return -1;

    }
    
    int isEmpty() {
        // Write your code here.
        return ind==-1;
    }
    
    int isFull() {
        // Write your code here.
        return ind==max-1;
    }
    
};
