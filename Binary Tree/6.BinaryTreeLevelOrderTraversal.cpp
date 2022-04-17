class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> v;
        if(root==NULL){
            return v;
        }
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector <int> level;
            for(int i=0; i<n; i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                level.push_back(curr->val);
            }
            v.push_back(level);
        }
        return v;
    }
};
