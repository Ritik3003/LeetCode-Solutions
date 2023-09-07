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
TreeNode* solve(vector<int>&pre, vector<int>&in, int start, int end, int &index){
    if(start>end){
        return NULL;
    }
    TreeNode* root=new TreeNode(pre[index++]);
    int mid=start;
    for(int i=start; i<=end; i++){
        if(root->val==in[i]){
            mid=i;
            break;
        }
    }
    root->left=solve(pre,in,start,mid-1,index);
    root->right=solve(pre,in,mid+1,end,index);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0){
            return NULL;
        }
        int index=0;
        return solve(preorder,inorder,0,n-1,index);
    }
};