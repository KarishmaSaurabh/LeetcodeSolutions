class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if(root==NULL ){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        int lt=(root->left) ? root->left->data : 0;
        int rt=(root->right) ? root->right->data : 0;
        if((lt+rt)!=root->data){
            return false;
        }
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
