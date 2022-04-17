class Solution {
public:
    int a=0;
    TreeNode *solve(vector <int> &p, vector <int> &i, int start, int end){
        if(start>end){
            return NULL;
        }
        TreeNode *root=new TreeNode(p[a++]);
        int index=0;
        for(int j=start; j<=end; j++){
            if(i[j]==root->val){
                index=j;
                break;
            }
        }
        root->left=solve(p,i,start,index-1);
        root->right=solve(p,i,index+1,end);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return solve(preorder,inorder,0,n-1);
    }
};
