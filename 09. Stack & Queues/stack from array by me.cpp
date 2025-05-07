
#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
    int ind, max;
    vector<int> st;
public:
Stack(int max) {
    this->max = max;
    ind = -1;
    st.resize(max);
}
~Stack() {
    st.clear();
    }

    bool push(int x){
        if(max > ind+1){
            st[++ind]=x;
            return 1;
        }
        else{
            cout<<"Stack Overflow\n";
            return 0;
        }
    }
    bool pop(){
        if(ind>=0){
            ind--;
            return 1;
        }
        else{
            cout<<"Stack Underflow\n";
            return 0;
        }
    }
    int top(){
        if(ind>=0){
            return st[ind];
        }
        else{
            cout<<"Stack is Empty\n";
            return 0;
        }
    }
    bool isEmpty(){
        return ind<0;
    }
    bool isFull(){
        return ind==max-1;
    }
};


int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    cout << "Top element is: " << s.top() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;
    return 0;

}