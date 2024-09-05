class LRUCache {
public:
    list<int>arr;
    unordered_map<int,pair<list<int>::iterator,int>>cache;
    int n;
    LRUCache(int capacity) {
        this->n=capacity;
    }
    void makeRecentUse(int key)
    {
        int value=cache[key].second;
        // delete from linked list
        arr.erase(cache[key].first);
        //insert in begin
        arr.push_front(key);

        // also update the address of key in map
        cache.erase(key);
        cache[key]={arr.begin(),value};
    }
    int get(int key) {
        //first check whether key value is present or not;
        if(cache.find(key)==cache.end())
        {
            return -1;
        }

        //if present
        //make the key recent use
        makeRecentUse(key);

        return cache[key].second;
    }
    
    void put(int key, int value) {
        //check whether key is present or not
        if(cache.find(key)!=cache.end())
        {
            arr.erase(cache[key].first);
            arr.push_front(key);
            cache.erase(key);
            cache[key]={arr.begin(),value};
        }

        //if not present insert it
        else
        {
                n--;
                arr.push_front(key);
                cache[key]={arr.begin(),value};
                
                if(n<0)
                {
                    cache.erase(arr.back());
                    arr.pop_back();
                    n++;
                }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */