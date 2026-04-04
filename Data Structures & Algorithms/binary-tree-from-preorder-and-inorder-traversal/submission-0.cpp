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
TreeNode* helper(vector<int>& preorder,int ps, int pe, vector<int>& inorder, int is , int ie){
    if(ps>pe || is>ie)return NULL;

    TreeNode* root = new TreeNode(preorder[ps]);
    
    int root_index = is;
    while(root_index <= ie && inorder[root_index] != root->val){
        root_index++;
    }

    int left_size = root_index - is;

    root->left = helper(preorder , ps+1, ps+left_size,  inorder , is, root_index-1);
    root->right = helper(preorder , ps+left_size+1 ,pe,  inorder , root_index+1 , ie);
    
    return root;

    
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        return helper(preorder , 0 , n-1 , inorder , 0 , n-1);
    }
};
