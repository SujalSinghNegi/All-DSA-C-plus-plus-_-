class MyStack {
    public:
    queue<int>q1;
    queue<int>q2;
    
        MyStack() {
        }
        
        void push(int x) {
            q1.push(x);
        }
        
        int pop() {
            int x =-1;
            while(!q1.empty()){
                if(x!=-1)q2.push(x);
                x = q1.front();
                q1.pop();
            }
            while(!q2.empty()){
                int y = q2.front();
                q1.push(y);
                q2.pop();
            }
            return x;
    
        }
        int top() {
                int x =-1;
            while(!q1.empty()){
                x = q1.front();
                q1.pop();
               q2.push(x);
            }
           swap(q1, q2);
            return x;
        }
        bool empty() {
            return q1.empty();
        }
    };
    