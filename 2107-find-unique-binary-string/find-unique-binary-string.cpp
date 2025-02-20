class Solution {
public:
    void solve(int i,string &temp,set<string>&st,string &ans)
    {
        int n=temp.size();
        if(i>=temp.size())
        {
            // cout<<temp<<endl;
            if(st.count(temp)==0)
            {
                ans=temp;
            } 
            return ; 
        } 

        if(ans!="") return ;

        for(char ch='0';ch<='1';ch++)
        {
            temp[i]=ch;
            solve(i+1,temp,st,ans);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st(nums.begin(),nums.end());
        int n=nums.size();
        string temp(n,'_');
        string ans="";
        solve(0,temp,st,ans);
        return ans;
        
    }
};