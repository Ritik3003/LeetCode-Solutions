/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

void solve(TreeNode* root, bool &check){
    if(root==NULL){
        return ;
    }
    solve(root->left,check);
    if(abs(height(root->left)-height(root->right))>1){
        check=false;
        return ;
    }
    solve(root->right,check);
}


    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool check=true;
        solve(root,check);
        return check;
    }
};