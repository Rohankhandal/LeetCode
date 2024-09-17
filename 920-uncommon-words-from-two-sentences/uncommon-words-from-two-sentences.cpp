class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>st1;
        unordered_map<string,int>st2;
        int prev=0;
        int i;
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]==' ')
            {
                string temp=s1.substr(prev,i-prev);
                // cout<<temp<<endl;
                st1[temp]++;
                prev=i+1;
                continue;
            }
        }
        string temp=s1.substr(prev);
        // cout<<temp<<endl;
         st1[temp]++;


        prev=0;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==' ')
            {
                string temp=s2.substr(prev,i-prev);
                // cout<<temp<<endl;
                st2[temp]++;
                prev=i+1;
                continue;
            }
        }
        st2[s2.substr(prev)]++;

        for(auto &it:st1)
        {
            if(st2[it.first]==0 && it.second==1)
            {
                ans.push_back(it.first);
            }
        }

         for(auto &it:st2)
        {
            if(st1[it.first]==0 && it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};