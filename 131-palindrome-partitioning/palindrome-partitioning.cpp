class Solution {
public:
    bool isPalindrome(string &s)
    {
        int l=0,r=s.size()-1;
        while(l<=r)
        {
           if(s[l]!=s[r]) return false;
           l++;r--;
        }
        return true;

    }
    void solve(int i,string &s,vector<vector<string>>&ans,vector<string>&temp)
    {
        int n=s.size();
        if(i>=s.size())
        {
            ans.push_back(temp);
            return ;
        }
        string str="";
        for(int idx=i;idx<n;idx++)
        {
            str+=s[idx];
            if(isPalindrome(str))
            {
                temp.push_back(str);
                solve(idx+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ans,temp);
        return ans;
    }
};