class LRUCache {
public:
class Node{
    public :

    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        val = val_;
    }
};

Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);

int cap;

unordered_map<int, Node*> mp;


    LRUCache(int capacity) {

        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
        
    }

    void addNode(Node* newNode){
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* delprev = delNode -> prev;
        Node* delnext = delNode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            Node* resNode = mp[key_];
            int res = resNode -> val;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_] = head -> next;
            return res;
        }

        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()){
            Node* existing = mp[key_];
            mp.erase(key_);
            deleteNode(existing);
        }

        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key_, value));
        mp[key_] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */