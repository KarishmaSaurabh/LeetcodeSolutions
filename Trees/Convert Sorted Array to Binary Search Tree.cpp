class Solution {
public:
    TreeNode* solve(vector<int> &nums,int i,int j){
        if(i>j){
            return NULL;
        }
        int m=i+(j-i)/2;
        TreeNode *p=new TreeNode(nums[m]);
        p->left=solve(nums,i,m-1);
        p->right=solve(nums,m+1,j);
        return p;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};
