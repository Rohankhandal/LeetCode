class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp=s;
        while(temp.find(part)!=string::npos)
        {
            int idx=temp.find(part);
            temp.erase(idx,part.size());
            // cout<<temp<<endl;
        }
        return temp;
    }
};