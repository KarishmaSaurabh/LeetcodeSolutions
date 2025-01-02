vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> pre,ino,po;
    vector<vector<int>> v;
    if(root==NULL){
        return v;
    }
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    while(!s.empty()){
        TreeNode *temp=s.top().first;
        int n=s.top().second;
        if(n==1){
            s.top().second++;
            pre.push_back(temp->data);
            if(temp->left){
                s.push({temp->left,1});
            }
        }
        else if(n==2){
            s.top().second++;
            ino.push_back(temp->data);
            if(temp->right){
                s.push({temp->right,1});
            }
        }
        else{
            po.push_back(temp->data);
            s.pop();
        }

    }
    v.push_back(ino);
    v.push_back(pre);
    v.push_back(po);
    return v;
}
