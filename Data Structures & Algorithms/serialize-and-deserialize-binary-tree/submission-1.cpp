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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)return "";
        string s;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            TreeNode* t = q.front();
            q.pop();

            if(t == NULL) s= s+"#,";
            else s= s+ to_string(t->val)+',';

            if(t!=NULL){
                q.push(t->left);
                q.push(t->right);
            }

        }return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0)return NULL;

        stringstream s(data);
        string str;
        getline(s, str , ',');

        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);


        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") t->left = NULL;
            else{
                TreeNode* nleft = new TreeNode(stoi(str));
                t->left = nleft;
                q.push(nleft);
            }

            getline(s, str, ',');
            if(str == "#") t->right = NULL;
            else{
                TreeNode* nRight = new TreeNode(stoi(str));
                t->right = nRight;
                q.push(nRight);
            }

        }return root;
    }
};
