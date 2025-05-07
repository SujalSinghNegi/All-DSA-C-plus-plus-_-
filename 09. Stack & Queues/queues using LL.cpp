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

class Queue {
public:
    int size;     // current number of elements
    int max;      // maximum capacity
    Node* head;
    Node* tail;

    Queue() {
        this->max = 1e6;
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    Queue(int max) {
        this->max = max;
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void push(int data) {
        if (size == max) {
            cout << "Queue is full" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = NULL;
        }
    }

    int getFront() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }
};
