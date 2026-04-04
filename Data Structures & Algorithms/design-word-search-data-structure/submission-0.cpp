class WordDictionary {
public:
struct Node{
    bool endW;
    Node* child[26];

    Node(){
        endW = false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* t = root;
        for(char c : word){
            if(t->child[c-'a'] == NULL) t->child[c-'a'] = new Node();
            t = t->child[c-'a'];
        }
        t->endW = true;
    }
    
    bool helper(Node* root , string word){
        Node* t = root;

        for(int i=0;i<word.size();i++){
            char c = word[i];

            if(c=='.'){

                for(int j=0;j<26;j++){
                    //if it is present 
                    if(t->child[j] != NULL){
                        if(helper(t->child[j] , word.substr(i+1) ) == true ) return true;
                    }
                }
                return false;
            }

            else if(t->child[ c -'a'] == NULL) return false;
            t = t->child[c - 'a'];
        }
        if(t->endW == true)return true;
        return false;
    }

    bool search(string word) {
        return helper(root , word);
    }
};
