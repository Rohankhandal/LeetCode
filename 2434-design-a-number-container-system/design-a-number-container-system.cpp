class NumberContainers {
public:
    unordered_map<int,int>cont; //index->number
    unordered_map<int,set<int>>smallIdx;//number -> index
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(cont.find(index)!=cont.end())
        {
            int oldNumber=cont[index];
            if(oldNumber!=number)
            {
                smallIdx[oldNumber].erase(index);
                if(smallIdx[oldNumber].empty())
                {
                    smallIdx.erase(oldNumber);
                }
            }
        }
            cont[index]=number;
            smallIdx[number].insert(index);
        
        
    }
    
    int find(int number) {
         if(smallIdx.find(number)!=smallIdx.end())
            return *smallIdx[number].begin();

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */