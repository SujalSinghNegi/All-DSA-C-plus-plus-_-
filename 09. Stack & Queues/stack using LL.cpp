#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
public:
    int size;
    int curSize;
    Node* head;

    Stack() {
        this->size = 1e6;
        this->head = NULL;
        this->curSize = 0;
    }

    Stack(int size) {
        this->size = size;
        this->head = NULL;
        this->curSize = 0;
    }

    void push(int data) {
        if (curSize == size) {
            cout << "Stack is full" << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        curSize++;
    }

    void pop() {
        if (curSize == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        curSize--;
    }

    bool isEmpty() {
        return curSize == 0;
    }

    bool isFull() {
        return curSize == size;
    }

    void top() {
        if (curSize == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << head->data << endl;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);           // Should print: Stack is full

    s.top();             // Should print: 5
    cout << s.size << endl;       // Should print: 5

    s.pop();
    s.top();             // Should print: 4
    cout << s.size << endl;       // Should still print: 5

    cout << s.isEmpty() << endl;  // Should print: 0
    cout << s.isFull() << endl;   // Should print: 0

    return 0;
}
