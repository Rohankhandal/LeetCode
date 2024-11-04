class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        auto idx=s.find("abc");
        while(s.size()>0)
        {
            if(idx==string::npos)
            {
                return false;
            }
            s.replace(idx,3,"");
            idx=s.find("abc");
        }
        return true;
    }
};