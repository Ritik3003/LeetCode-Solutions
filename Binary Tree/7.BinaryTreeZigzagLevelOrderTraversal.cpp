class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        if(!root) return ans;
        bool flag=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
             vector<int> curr;
            for(int i=0;i<size;i++){
                 root=q.front();
                 curr.push_back(root->val);
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(flag){
                reverse(curr.begin(),curr.end());
            }
           
                ans.push_back(curr);
            
         
           flag=!flag;
        }
        return ans;
    }
};
