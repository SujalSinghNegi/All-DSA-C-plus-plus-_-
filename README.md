LEARN # DSA Problems with Proper Comments and Solutions

## Table of Contents
1. [Arrays](#arrays)
2. [Linked Lists](#linked-lists)
3. [Stacks and Queues](#stacks-and-queues)
4. [Trees](#trees)
5. [Graphs](#graphs)

## Arrays
### Problem 1: Maximum Subarray Sum
```python
def max_subarray_sum(arr):
    """
    Returns the maximum subarray sum.

    Args:
        arr (list): A list of integers.

    Returns:
        int: The maximum subarray sum.
    """
    max_sum = float('-inf')
    current_sum = 0

    for num in arr:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)

    return max_sum

# Example usage:
arr = [-2, -3, 4, -1, -2, 1, 5, -3]
print("Maximum subarray sum:", max_subarray_sum(arr))
```

## Linked Lists
### Problem 1: Reverse Linked List
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

# Example usage:
ll = LinkedList()
ll.append(1)
ll.append(2)
ll.append(3)
ll.append(4)
ll.append(5)

print("Original Linked List:")
ll.print_list()

ll.reverse()

print("Reversed Linked List:")
ll.print_list()
```

## Stacks and Queues
### Problem 1: Implement Stack using List
```python
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        return None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

# Example usage:
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)

print("Stack size:", stack.size())
print("Top element:", stack.peek())
print("Popped element:", stack.pop())
print("Stack size after pop:", stack.size())
```

## Trees
### Problem 1: Binary Tree Traversal
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data < node.data:
            if node.left:
                self._insert(data, node.left)
            else:
                node.left = Node(data)
        else:
            if node.right:
                self._insert(data, node.right)
            else:
                node.right = Node(data)

    def inorder_traversal(self):
        self._inorder_traversal(self.root)

    def _inorder_traversal(self, node):
        if node:
            self._inorder_traversal(node.left)
            print(node.data, end=" ")
            self._inorder_traversal(node.right)

    def preorder_traversal(self):
        self._preorder_traversal(self.root)

    def _preorder_traversal(self, node):
        if node:
            print(node.data, end=" ")
            self._preorder_traversal(node.left)
            self._preorder_traversal(node.right)

    def postorder_traversal(self):
        self._postorder_traversal(self.root)

    def _postorder_traversal(self, node):
        if node:
            self._postorder_traversal(node.left)
            self._postorder_traversal(node.right)
            print(node.data, end=" ")

# Example usage:
bt = BinaryTree()
bt.insert(8)
bt.insert(3)
bt.insert(10)
bt.insert(1)
bt.insert(6)
bt.insert(14)
bt.insert(4)
bt.insert(7)
bt.insert(13)

print("Inorder traversal:")
bt.inorder_traversal()
print("\nPreorder traversal:")
bt.preorder_traversal()
print("\nPostorder traversal:")
bt.postorder_traversal()
```

## Graphs
### Problem 1: Breadth-First Search (BFS)
```python
from collections import deque

class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, u, v):
        if u not in self.adj_list:
            self.adj_list[u] = []
        self.adj_list[u].append(v)

    def bfs(self, start):
        visited = set()
        queue = deque([start])
        visited.add(start)

        while queue:
            node = queue.popleft()
            print(node, end=" ")

            if node in self.adj_list:
                for neighbor in self.adj_list[node]:
                    if neighbor not in visited:
                        queue.append(neighbor)
                        visited.add(neighbor)

# Example usage:
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(2, 4)
g.add_edge(3, 5)

print("BFS traversal:")
g.bfs(0)
```ALL DSA PROBLEMS WITH PROPER COMMENTS AND SOLUTION
