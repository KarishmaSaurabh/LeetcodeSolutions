class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int i,int j,int &preIn,unordered_map<int,int> &m){
        if(i>j){
            return NULL;
        }
        TreeNode* p=new TreeNode(preorder[preIn++]);
        int inRoot=m[p->val];
        p->left=solve(preorder,inorder,i,inRoot-1,preIn,m);
        p->right=solve(preorder,inorder,inRoot+1,j,preIn,m);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int preIn=0;
        TreeNode *root= solve(preorder,inorder,0,n-1,preIn,m);
        return root; 
        
    }
};
