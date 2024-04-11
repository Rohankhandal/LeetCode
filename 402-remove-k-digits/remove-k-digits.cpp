class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int i=0;
        while(i<num.size())
        {
            while(ans.size()>0 && ans.back()>num[i] && k)
            {
                ans.pop_back();
                k--;

            }
            ans.push_back(num[i]);
            i++;
        }
        
        while(ans.size()>0 && k)
        {
            ans.pop_back();
            k--;
        }
        //we have to deal with preceding zeros in answer
        string result="";
        i=0;
        while(ans[i]=='0')
        {
            i++;
        }
        
        result=ans.substr(i,ans.size());
        
        if(result=="") return "0";

        return result;
    }
};