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
    void solve(TreeNode *root, map<int, int>&m){
        if(root==NULL){
            return ;
        }
        solve(root->left,m);
        m[root->val]++;
        solve(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        map <int, int> m;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        solve(root,m);
        int ma=INT_MIN;
        for(auto it: m){
            ma=max(it.second,ma);
        }
        for(auto it: m){
            if(ma==it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};