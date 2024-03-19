class Solution {
public:
    string removeOccurrences(string s, string part) {
        int index=0;
        while(s.find(part)!=string::npos)
        {
            index=s.find(part);
            s.erase(index,part.size());
        }
        return s;
    }
};