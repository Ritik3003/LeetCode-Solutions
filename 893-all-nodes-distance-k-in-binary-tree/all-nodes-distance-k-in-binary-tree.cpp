/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

void mark_parent(TreeNode*root, map<TreeNode*, TreeNode*>&parent){
    if(root==NULL){
        return ;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()){
        int n=q.size();
        for(int i=0; i<n; i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }

}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<TreeNode*, TreeNode*> parent;
        mark_parent(root,parent);
        int level=0;
        map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(q.size()){
            level++;
            if(level-1==k){
                break;
            }
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited[node->left]==false){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && visited[node->right]==false){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && visited[parent[node]]==false){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        while(q.size()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};