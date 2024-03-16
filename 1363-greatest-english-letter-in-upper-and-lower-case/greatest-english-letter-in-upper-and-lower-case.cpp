class Solution {
public:
    string greatestLetter(string s) {
        int n=s.size();
        string ans="";
        unordered_map<int,int>mp;
        for(auto &it:s)
        {
            mp[it]++;
        }
        char max='0';
        for(auto &it:s)
        {
            if((it>='a'&& it<='z') && it>max && mp.find(it-32)!=mp.end())
            {
                max=it;
            }
            if((it>='A'&& it<='Z') && it>max && mp.find(it+32)!=mp.end())
            {
                max=it;
            }
        }
        if(max!='0')
        {
        //   cout<<max<<endl;
          max=max-32;
          ans.push_back(max);
        } 
        return ans;

    }
};