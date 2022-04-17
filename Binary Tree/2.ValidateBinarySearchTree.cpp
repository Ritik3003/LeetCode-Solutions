bool solve(TreeNode* root, TreeNode*& prev){
        if(root==NULL){
            return true;
        }
        bool l=solve(root->left,prev);
        if(prev!=NULL && prev->val>=root->val){
            return false;
        }
        prev=root;
        bool r=solve(root->right,prev);
        return l&&r;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=NULL;
        return solve(root,prev);
    }
