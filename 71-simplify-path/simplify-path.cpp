class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);           
        string tokken;
        vector<string>temp;
        while(getline(ss,tokken,'/'))   //tokenize words on the basis of '/'
        {
            if(tokken=="." || tokken=="")
            {
                continue;
            }
            if(tokken!="..")
            {
                temp.push_back(tokken);
            }
            else if(!temp.empty())
            {
                temp.pop_back();
            }
        }
        string ans="";
        if(temp.size()==0) return "/";
        for(auto &it:temp)
        {
            ans+="/"+it;
        }
        return ans;
    }
};