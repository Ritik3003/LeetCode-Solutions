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

TreeNode* solve(vector<int>&p,vector<int>&i, int &index, int start, int end ){
    if(start>end){
        return NULL;
    }
    TreeNode* root=new TreeNode(p[index++]);
    int current=index;
    for(int j=start; j<=end; j++){
        if(i[j]==root->val){
            current=j;
            break;
        }
    }
    root->left=solve(p,i,index,start,current-1);
    root->right=solve(p,i,index,current+1,end);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0){
            return NULL;
        }
        int index=0;
        return solve(preorder,inorder,index,0,n-1);
    }
};