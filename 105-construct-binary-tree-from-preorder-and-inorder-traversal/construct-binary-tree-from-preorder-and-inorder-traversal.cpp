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
TreeNode* solve(vector<int>&p, vector<int>&i, int start, int end, int &index){
    if(start>end){
        return NULL;
    }
    TreeNode *root=new TreeNode(p[index++]);
    int x=0;
    for(int j=start; j<=end; j++){
        if(i[j]==root->val){
            x=j;
            break;
        }
    }
    root->left=solve(p,i,start,x-1,index);
    root->right=solve(p,i,x+1,end,index);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=inorder.size();
        return solve(preorder,inorder,0,n-1,index);
    }
};