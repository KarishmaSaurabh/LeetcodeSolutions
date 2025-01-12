class Solution
{
    public:
    void predecessor(Node *root,Node* &pre,int key){
         while(root){
            if(root->key>=key){
                root=root->left;
            }
            else{
                pre=root;
                root=root->right;
            }
        }
        return;
    }
    void successor(Node *root,Node* &suc,int key){
        while(root){
            if(root->key<=key){
                root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre=NULL;
        predecessor(root,pre,key);
        suc=NULL;
        successor(root,suc,key);
        return;
    }
};
