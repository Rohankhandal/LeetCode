class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();

        for(auto &it:arr)
        {
            if(mp.find(it*2)!=mp.end()) return true;
            if(it%2==0 && mp.find((it)/2)!=mp.end()) return true;

            mp[it]++;
        }
        return false;
    }
};