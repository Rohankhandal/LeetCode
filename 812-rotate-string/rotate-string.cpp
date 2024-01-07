class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1=s.size();
        int len2=goal.size();
        if(len1>len2 || len2>len1)
        {
            return false;
        }

        s=s+s;       //make a big string or append s in s.
        bool ans=s.find(goal)!=string::npos;


        return ans;
    }
};