/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*>mp;

    void dfs(Node* node , Node* clone){

        for(Node* n : node->neighbors){
            
            //not found in map;  create new node and push in map as well as in node->neighbour
            if(mp.find(n) == mp.end()){
                Node* clone_n = new Node(n->val);
                mp[n] = clone_n;
                clone->neighbors.push_back(clone_n);

                dfs(n , clone_n);
            }


            else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;

       mp.clear();
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        dfs(node, newNode);
        return newNode;
    }
};
