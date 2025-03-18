class Solution {
public:
    void f(vector<int>&digits,set<string>&st,string temp,int n,unordered_map<int,int>&mp)
    {
        if(temp.size()==3) 
        {
            if((temp[2]-'0')%2==0 && temp[0]!='0')
            {
                st.insert(temp);
                // cout<<temp<<endl;
            }
            return ;
        }

        for(int idx=0;idx<n;idx++)
        {
            if(mp[digits[idx]]>0)
            {
                temp.push_back(digits[idx]+'0');
                mp[digits[idx]]--;
                f(digits,st,temp,n ,mp);
                mp[digits[idx]]++;
                temp.pop_back();
            }
            
        }
    }
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<string>st;
        string temp="";
        unordered_map<int,int>mp;
        for(auto &it:digits) mp[it]++;
        f(digits,st,temp,n,mp);
        return st.size();
    }
};