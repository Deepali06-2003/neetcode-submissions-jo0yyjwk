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
void helper(TreeNode* root , int& ans, int min){

    if(root == NULL)return;
    if(root->val >= min){
        min= root->val;
        ans++;
    }
    helper(root->left, ans, min);
    helper(root->right , ans , min);
}
    int goodNodes(TreeNode* root) {
        int ans=0;
        

        helper(root, ans , INT_MIN);
        return ans;
    }
};
