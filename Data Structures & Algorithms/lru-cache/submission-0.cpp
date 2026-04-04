class LRUCache {
    private:

    struct Node{
        int key , value ;
        Node* prev;
        Node* next;

        Node(int k , int v):key(k), value(v), prev(NULL), next(NULL){}
    };

    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int , Node*>mp;

    void Remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void ToAddFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0 , 0);
        tail = new Node(0 , 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end())return -1;

        Node* temp = mp[key];
        Remove(temp);
        ToAddFront(temp);

        return temp->value;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            temp->value = value;

            Remove(temp);
            ToAddFront(temp);
        }
        else{
            if(mp.size() == capacity){
                Node* temp = tail->prev;
                Remove(temp);
                mp.erase(temp->key);
                delete(temp);
            }

            Node* newTemp = new Node(key, value);
            mp[key] = newTemp;
            ToAddFront(newTemp);

        }
    }
};
