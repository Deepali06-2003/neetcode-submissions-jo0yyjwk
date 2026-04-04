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
int ans=0;
void helper(TreeNode* root , int c){
    if(root == NULL)return;

    c++;
    ans = max(ans , c);
    helper(root->left , c);
    helper(root->right , c);
}
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)return 0;
        int c=0;
        helper(root , c);
        return ans;
    }
};
