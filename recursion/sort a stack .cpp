
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void pushCorrect(stack<int>&s, int node, int i){
    if(s.size()<=i){
        s.push(node);
        return;
    }
    int ele = s.top();
    s.pop();
    if(node>ele)swap(ele,node);
    pushCorrect(s, node, i);
    s.push(ele);
}
void SortedStack :: sort()
{
   if(s.empty()) return;
   //Your code here
   int n= s.size();
   for(int i=0; i<n; i++){
   int node = s.top();
   s.pop();
       
       pushCorrect(s, node,i);
   }
   
}