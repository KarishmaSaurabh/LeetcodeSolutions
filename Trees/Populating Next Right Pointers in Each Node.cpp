//O(n) space soln

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* k=q.front();
            q.pop();
            if(k!=NULL){
               k->next=q.front();
            if(k->left){
                q.push(k->left);
            }
            if(k->right){
                q.push(k->right);
            }
            }
            else if(!q.empty()){
                q.push(NULL);
            }
            
        }
        return root;
    }
};

//O(1) space

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        Node* l=root->left,*r=root->right,*n=root->next;
        if(l!=NULL){
           l->next=r;
        if(n!=NULL){
            r->next=root->next->left;
        }
        connect(root->left);
        connect(root->right);
        }
        return root;
    }
};
