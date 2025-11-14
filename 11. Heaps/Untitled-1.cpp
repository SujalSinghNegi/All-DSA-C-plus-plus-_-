#include <bits/stdc++.h>


using namespace std;

class BinaryHeap {
public:
    // Maximum elements that can be stored in heap
    int capacity;  
    
    // Current no of elements in heap
    int size;  
    
    // Array for storing the keys
    int* arr;  

    BinaryHeap(int cap) {
        // Assigning the capacity
        capacity = cap;  
        
        // Initially size of heap is zero
        size = 0;  
        
        // Creating an array
        arr = new int[capacity];  
    }

    // Returns the parent of ith Node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the left child of ith Node
    int left(int i) {
        return 2 * i + 1;
    }

    // Returns the right child of the ith Node
    int right(int i) {
        return 2 * i + 2;
    }

    list<int>ls;
    vector<int>s;


    // Insert a new key x
    void Insert(int x) {
        if (size == capacity) {
            cout << "Binary Heap Overflow" << endl;
            return;
        }

        // Insert new element at end
        arr[size] = x;  

        // Store the index, for checking heap property
        int k = size;  

        // Increase the size
        size++;  

        // Fix the min heap property
        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    void Heapify(int ind) {
        // Right child
        int ri = right(ind);  
        
        // Left child
        int li = left(ind);  
        
        // Initially assume violated value is minimum
        int smallest = ind;  

        if (li < size && arr[li] < arr[smallest])
            smallest = li;

        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;

        // If the Minimum among the three nodes is not the parent itself,
        // then swap and call Heapify recursively
        if (smallest != ind) {
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    int getMin() {
        return arr[0];
    }

    int ExtractMin() {
        if (size <= 0)
            return INT_MAX;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        // Copy last Node value to root Node
        arr[0] = arr[size - 1];  

        size--;

        // Call heapify on root node
        Heapify(0);  

        return mini;
    }

    void Decreasekey(int i, int val) {
        // Updating the new value
        arr[i] = val;  

        // Fixing the Min heap
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.Decreasekey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;

    return 0;
}

