class Solution {
  public:
   
 Node* connection(unordered_map<Node*,Node*>&mpp, Node* root, int target){
    Node* del=NULL;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int s= q.size();
        for(int i=0; i<s; i++){
            Node* temp= q.front();
            q.pop();
            if(temp->data==target)del= temp;
            if(temp->left){
                q.push(temp->left);
                mpp[temp->left]= temp;
            }
            if(temp->right){
                q.push(temp->right);
                mpp[temp->right]= temp;
            }
        }

    }
    return del;
}

int time(unordered_map<Node*, Node*>mpp, Node* del ){
    queue<Node*>q;
    q.push(del);
    unordered_map<Node*, bool>vis;
    vis[del]=1;
    int ans=0;
    while(!q.empty()){
        int s= q.size();
        bool f = 0;
        for(int i= 0;i<s;  i++){ 
             Node* temp = q.front();
             q.pop();
             if(temp->left &&  !vis[temp->left]){
                f=1;
                vis[temp->left]=1;
                q.push(temp->left);
             }
             if(temp->right &&  !vis[temp->right]){
                f=1;
                vis[temp->right]=1;
                q.push(temp->right);
             }
             if(mpp[temp] && !vis[mpp[temp]]){
                f=1;
                vis[mpp[temp]]=1;
                q.push(mpp[temp]);
             }
        }
        if(f)ans++;
    }
    return ans;

}
int minTime(Node* root, int target){

    unordered_map<Node*, Node*>mpp; // a hashmap connection of a node to parent node
    Node* del= connection(mpp, root, target);
    int ans = time(mpp, del);
    return ans;

}

};