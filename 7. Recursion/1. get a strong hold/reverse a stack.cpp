class Solution{
       public:
       void pushCorrect(stack<int>&st, int ele, int i){
           if(st.size()==i){
               st.push(ele);
               return;
           }
           int node= st.top();
           st.pop();
           pushCorrect(st, ele, i);
           st.push(node);
       }
           void Reverse(stack<int> &st){
               if(st.empty())return;
              int n= st.size();
              
              for(int i=0; i<n; i++){
                  int node = st.top();
              st.pop();
              pushCorrect(st, node, i);
              
              
              }
           }
       };