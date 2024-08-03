class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        
        vector<int>hash(1001,0);
        for(int i=0;i<n;i++)
        {
            hash[target[i]]++;
            hash[arr[i]]--;
        }
        for(auto &it:hash)
        {
            if(it!=0) return false;
        }
        return true;
    }
};