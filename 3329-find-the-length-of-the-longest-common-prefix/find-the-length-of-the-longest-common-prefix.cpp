class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<arr1.size();i++)
        {
            string s=to_string(arr1[i]);
            for(int l=1;l<=s.size();l++)
            {
                string temp=s.substr(0,l);
                mp[temp]++;
            }
        }
        int maxAns=0;
        for(int i=0;i<arr2.size();i++)
        {
            string s=to_string(arr2[i]);
            for(int l=1;l<=s.size();l++)
            {
                string temp=s.substr(0,l);
                if(mp.find(temp)!=mp.end())
                {
                    // cout<<temp<<endl;
                    maxAns=max(maxAns,l);
                }
            }
        }
        return maxAns;
        
    }
};