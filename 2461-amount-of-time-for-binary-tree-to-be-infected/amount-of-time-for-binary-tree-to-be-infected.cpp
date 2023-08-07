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
TreeNode *target=NULL;

void mark_parent(TreeNode* root, map<TreeNode*, TreeNode*>&parent, int start){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode* current_node=q.front();
        q.pop();
        if(start==current_node->val){
            target=current_node;
        }
        if(current_node->left){
            parent[current_node->left]=current_node;
            q.push(current_node->left);
        }
        if(current_node->right){
            parent[current_node->right]=current_node;
            q.push(current_node->right);
        }
    }
}

    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        map<TreeNode*, TreeNode*> parent;
        mark_parent(root,parent,start);
        map<TreeNode*, bool> visited;
        visited[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        while(q.size()){
            ans++;
            int length=q.size();
            for(int i=0; i<length; i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && visited[curr->left]!=true){
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && visited[curr->right]!=true){
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr] && visited[parent[curr]]==false){
                    visited[parent[curr]]=true;
                    q.push(parent[curr]);
                }
            }
        }
        return ans-1;
    }
};