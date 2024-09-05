// //Approach-1 (Brute Force)
// class LRUCache {
// public:
    
//     vector<pair<int, int>> cache;
//     int n;
    
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
        
//         for(int i = 0; i<cache.size(); i++) {  //find the key 
            
//             if(cache[i].first == key) {  //if present
//                 int val = cache[i].second;
                
//                 pair<int, int> temp = cache[i];
//                 cache.erase(cache.begin()+i);  //delete the key from vector
//                 cache.push_back(temp); //and push_back To last (means it is recently used)
                
//                 return val; //return the value if key is present
//             }
            
//         }
        
//         return -1;  //if key is not present , return -1;
        
//     }
    
//     void put(int key, int value) {
//         //step-1:- search in vector , that key entry is present or not in vector
//         //   => if present delete old entry and insert new entry with new value
//         //step:2:- if key entry is not found in vector, then simply insert in vector
//         //step;3:- check for threshold also , if capcity exceed , then delete entry from starting of vector bcz
//         //in starting least recently used (bhout pehele use hua element hoga)
//         for(int i = 0; i<cache.size(); i++) {
            
//             if(cache[i].first == key) {
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key, value});
//                 return;
//             }
//         }
        
//         if(cache.size() == n) {
//             cache.erase(cache.begin());
//             cache.push_back({key, value});
//         } else {
//             cache.push_back({key, value});
//         }
        
//     }
// };



//Approach-2 (Optimal)
class LRUCache {
public:
    list<int> dll; //it contains the key(double linked list)
    map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {

        //1.delete entry of key from linked list
        //2.insert new entry in linked list
        //3. also do entry of new element in map
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))  //if entry is not present
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            //if entry is present
            //update the value and make it recently used
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            //if entry is not present
            //insert the entry in linked list and map

            //decrase the capacity
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;  
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());  //delete the LRU element , which is last node of linked list from map
            dll.pop_back(); //delete also from linked list
            capacity++;
        }
    }
};