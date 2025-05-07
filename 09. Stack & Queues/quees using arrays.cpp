#include <bits/stdc++.h>
using namespace std;

class Queue {
    int start, end;
    vector<int> q;
    int capacity, curSize;

public:
    Queue(int s) {
        capacity = s;
        start = -1;
        end = -1;
        curSize = 0;
        q.resize(capacity);
    }

    void push(int x) {
        if (curSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        if (start == -1) start = 0;
        end = (end + 1) % capacity;
        q[end] = x;
        curSize++;
    }

    void getFront() {
        if (curSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front: " << q[start] << endl;
    }

    void pop() {
        if (curSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (start == end) {
            start = end = -1;
        } else {
            start = (start + 1) % capacity;
        }
        curSize--;
    }

    void size() {
        cout << "Size: " << curSize << endl;
    }

    void empty() {
        if (curSize == 0) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue is not empty" << endl;
        }
    }
};

int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.getFront();  // Should print 10
    q.pop();
    q.getFront();  // Should print 20
    q.size();      // Should print 2
    q.empty();     // Should print not empty

    q.pop();
    q.pop();
    q.empty();     // Should print empty

    q.pop();       // Should print queue is empty
    return 0;
}
