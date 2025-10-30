class LRUCache {
public:
     int cap;
    list<pair<int, int>> dll; // {key, value} - front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key -> iterator in list

    LRUCache(int capacity){
        cap = capacity;
    }

    int get(int key) {
        // If key not found
        if (mp.find(key) == mp.end()) return -1;

        // Move accessed item to front (most recently used)
        auto it = mp[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, erase it first
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // If capacity full, remove least recently used (back)
        else if (dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        // Insert new key-value at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */