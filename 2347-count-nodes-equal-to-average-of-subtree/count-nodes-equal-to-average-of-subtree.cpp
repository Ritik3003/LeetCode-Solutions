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
int ans=0;
int count(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}

int sum(TreeNode * root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->val;
}

    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(sum(root)/count(root)==root->val){
            ans++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;
    }
};