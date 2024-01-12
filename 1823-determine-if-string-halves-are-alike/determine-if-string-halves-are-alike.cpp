class Solution {
public:
    int isvowel(string str)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int count = 0;
            for (char c : str) {
                if (vowels.count(c) > 0) {
                    count++;
                }
            }
            return count;
    }
   
    bool halvesAreAlike(string s) {
        int size=s.size();
        string a=s.substr(0,size/2);
        string b=s.substr(size/2);
        
        if(isvowel(a)==isvowel(b))
        {
            return true;
        }
        return false;
    }
};