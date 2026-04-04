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

int max_l(TreeNode* root, int ans){
    if(root==NULL)return ans;
    ans = max(root->val, ans);
    return max_l(root->right, ans);
}

int min_l(TreeNode* root, int ans){
    if(root==NULL)return ans;
    ans = min(root->val, ans);
    return min_l(root->left, ans);
}


    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;

        if(root->left){
            int rl = INT_MIN;
            rl = max_l(root->left ,rl);
            if(rl >= root->val)return false;
        }
        if(root->right){
            int rr = INT_MAX;
            rr= min_l(root->right , rr);
            if(rr <= root->val)return false;
        }
        return isValidBST(root->left)&& isValidBST(root->right);
    }
};
