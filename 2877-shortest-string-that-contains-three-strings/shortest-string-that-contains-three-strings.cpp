class Solution {
public:
    string mergeString(string s,string t)
    {
        int idx=-1;
        for(int i=0;i<s.size();i++)
        {
            int left=i,right=0;
            while(left<s.size() && right<t.size())
            {
                if(s[left]==t[right])
                {
                    left++;
                    right++;
                }
                else 
                {
                    break;
                }
            }
            if(left==s.size())
            {
                idx=right;
                break;
            }
            if(right==t.size()) return s;
        }
        if(idx==-1) return s+t;
        string str=s;
        for(int i=idx;i<t.size();i++)  //add remaining part 
        {
            str.push_back(t[i]);
        }
        return str;
    }
    string f(string a,string b,string c)
    {
        string finalStr="";
        finalStr=mergeString(a,b);
        finalStr=mergeString(finalStr,c);

        return finalStr;
    }
    string minimumString(string a, string b, string c) {
        vector<string>strs={f(a,b,c),f(a,c,b),f(b,a,c),f(b,c,a),f(c,b,a),f(c,a,b)};
        int size=301;  //max size of string
        string ans="";
        for(auto str:strs)
        {
            if(str.size()<size)
            {
                ans=str;
                size=ans.size();
            }
            else if(str.size()==size)
            {
                ans=min(ans,str);
            }
        }
        return ans;
    }
};