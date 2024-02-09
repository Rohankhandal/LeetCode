class Solution {
public:
static bool comparator(pair<int,int> &a  , pair<int,int> & b){
      return a.first > b.first ;
    }
    string frequencySort(string s) {
        vector<pair<int,int>>vec;
        unordered_map<char,int>mp;
        for(auto &ch:s)
        {
            mp[ch]++;
        }
        //store frequency in vector
        for(auto &it:mp)
        {
            char ch=it.first;
            int freq=it.second;
            vec.push_back({freq,ch});
        }
        sort(vec.begin(),vec.end(),comparator);  //sort the vector in descending order
        string ans="";
// for(auto &it:vec)
// {
//     cout<<it.first<<" "<<(char)it.second<<endl;
// }
        for(auto &it:vec)
        {
            while(it.first)
            {
                ans+=it.second;
                it.first--;
            }
            
        }
        return ans;
    }
};