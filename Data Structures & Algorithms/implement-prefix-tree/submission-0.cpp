class PrefixTree {
public:
struct Node{
    Node* child[26];
    bool endW;

    Node(){
        for(int i=0;i<26;i++)child[i]= NULL;
        endW = false;
    }
};

Node* root;

    PrefixTree() {
        root = new Node();
    }
    


    void insert(string word) {
        
        Node* t = root;
        for(char c: word){

            if(t->child[c-'a']== NULL){
                t->child[c-'a']= new Node();
            }
            t = t->child[c-'a'];
        }
        t->endW = true;
    }
    


    bool search(string word) {
        Node* t = root;
        for(char c: word){

            if(t->child[c-'a']== NULL)return false;

            t = t->child[c-'a'];
        }
        if(t->endW == true)return true;
        return false;
    }


    
    bool startsWith(string prefix) {
        Node* t = root;
        for(char c: prefix){

            if(t->child[c-'a']== NULL)return false;

            t = t->child[c-'a'];
        }
        return true;
    }
};
