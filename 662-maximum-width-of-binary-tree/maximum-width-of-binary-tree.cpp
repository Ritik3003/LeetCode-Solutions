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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        long long int ans=0;
        while(q.size()){
            long long int id=q.front().second;
            long long int first=0;
            long long int last=0;
            int n=q.size();
            for(int i=0; i<n; i++){
                long long int index=q.front().second-id;
                TreeNode* curr=q.front().first;
                q.pop();
                if(i==0){
                    first=index;
                }
                if(i==n-1){
                    last=index;
                }
                if(curr->left){
                    q.push({curr->left,2*index+1});
                }
                if(curr->right){
                    q.push({curr->right,2*index+2});
                }
            }
            ans=max(last-first+1,ans);
        }
        return ans;
    }
};