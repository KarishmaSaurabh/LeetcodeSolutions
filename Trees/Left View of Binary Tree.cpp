/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> v;
       if(root==NULL){
           return v;
       }
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int c=q.size();
           for(int i=0;i<c;i++){
                Node *k=q.front();
                q.pop();
               if(i==0){
                   v.push_back(k->data);
               }
               if(k->left!=NULL){
                   q.push(k->left);
               }
               if(k->right!=NULL){
                   q.push(k->right);
               }
           }
       }
       return v;
    }
};
