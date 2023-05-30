class MyHashSet {
public:
vector<int> arr;
    MyHashSet() {
        
    }
    
    void add(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if(i == arr.end()){
            arr.push_back(key);
        }
    }
    
    void remove(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if(i != arr.end()){
            arr.erase(i);
        }
    }
    
    bool contains(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if(i != arr.end()){
            return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */