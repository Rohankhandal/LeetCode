class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val)==mp.end(val))
        {
            arr.push_back(val);
            mp[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        {
            return false;
        }
             int idx=mp[val];  //access the index which we have to remove
            int lastElement=arr.back();
            arr.back()=val;
            arr[idx]=lastElement;
            mp[lastElement]=idx;
            arr.pop_back();
            mp.erase(val);
            
            return true;
        
        
    }
    
    int getRandom() {
        int n=arr.size();
        int randomElement=rand()%n;
        return arr[randomElement];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */