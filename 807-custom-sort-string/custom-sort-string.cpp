class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int>mp1;
        for(auto &it:order)
        {
            mp1[it]++;
        }
        //store s in mp2 map
        unordered_map<char,int>mp2;
        for(auto &it:s)
        {
            mp2[it]++;
        }
        //find order string characters correspoinding to s string
        // and into ans string;
        for(auto &it:order)
        {
            if(mp2.find(it)!=mp2.end())
            {
                while(mp2[it]--)
                  ans+=it;
                //remove occurrence of it element in mp2
                    mp2.erase(it);
              
            }
        }
        //now add all remaming elements of mp2 map in ans string
        for(auto &it:mp2)
        {
            while(it.second--)
              ans+=(it.first);
        }
        return ans;

    }
};