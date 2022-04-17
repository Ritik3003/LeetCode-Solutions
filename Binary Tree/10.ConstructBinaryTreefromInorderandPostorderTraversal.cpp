class Solution {
public:
    TreeNode *solve(vector <int> in, vector <int> post, int start, int end, int &a){
        if(start>end){
            return NULL;
        }
        TreeNode *node =new TreeNode(post[a]);
        a--;
        int index=0;
        for(int i=start; i<=end; i++){
            if(in[i]==node->val){
                index=i;
                break;
            }
        }
        node->right=solve(in,post,index+1,end,a);
        node ->left=solve(in,post,start,index-1,a);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size()-1;
        return solve(inorder, postorder,0,inorder.size()-1,n);
    }
};
