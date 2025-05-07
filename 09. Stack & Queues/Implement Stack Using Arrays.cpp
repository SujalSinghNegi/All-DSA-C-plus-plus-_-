// C++ program to create a stack with
// given capacity


// Complexity Analysis:
// Time Complexity:
// push: O(1)
// pop: O(1)
// peek: O(1)
// is_empty: O(1)
// is_full: O(1)
// Auxiliary Space: O(n), where n is the number of items in the stack.

#include <bits/stdc++.h>
using namespace std; 

class Stack { 
    int top, cap; 
    int *a; 

public: 
    Stack(int cap) { 
        this->cap = cap; 
        top = -1; 
        a = new int[cap]; 
    } 

    ~Stack() { 
        delete[] a; 
    } 

    bool push(int x) { 
        if (top >= cap - 1) { 
            cout << "Stack Overflow\n"; 
            return false; 
        } 
        a[++top] = x; 
        return true; 
    } 

    int pop() { 
        if (top < 0) { 
            cout << "Stack Underflow\n"; 
            return 0; 
        } 
        return a[top--]; 
    } 

    int peek() { 
        if (top < 0) { 
            cout << "Stack is Empty\n"; 
            return 0; 
        } 
        return a[top]; 
    } 

    bool isEmpty() { 
        return top < 0; 
    } 
}; 

int main() { 
    Stack s(5); 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " popped from stack\n"; 

    cout << "Top element is: " << s.peek() << endl; 

    cout << "Elements present in stack: "; 
    while (!s.isEmpty()) { 
        cout << s.peek() << " "; 
        s.pop(); 
    } 

    return 0; 
}