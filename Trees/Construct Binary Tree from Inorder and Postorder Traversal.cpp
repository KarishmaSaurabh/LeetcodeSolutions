class Solution {
public:
    unordered_map<int,int> m;
    TreeNode* solve(vector<int>& postorder,int &postIn,int i,int j){
        if(i>j){
            return NULL;
        }
        TreeNode *p=new TreeNode(postorder[postIn--]);
        int inRoot=m[p->val];
        p->right=solve(postorder,postIn,inRoot+1,j);
        p->left=solve(postorder,postIn,i,inRoot-1);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int postIn=n-1;
        TreeNode* root=solve(postorder,postIn,0,n-1);
        return root;
    }
};
