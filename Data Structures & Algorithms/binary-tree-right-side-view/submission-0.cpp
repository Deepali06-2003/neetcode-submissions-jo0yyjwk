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

void helper(TreeNode* root,vector<int>& res, vector<int>curr){

    if(root == NULL)return;

    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){
        int s = q.size();
        curr.clear();

        for(int i =0;i<s;i++){
            TreeNode* v = q.front();
            q.pop();

            curr.push_back(v->val);
            if(v->left) q.push(v->left);
            if(v->right) q.push(v->right);
        }
        res.push_back( curr[curr.size()-1] );

    }
}

    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        vector<int>curr;

        if(root == NULL)return res;
        
        helper(root, res , curr);
        return res;
    }
};
