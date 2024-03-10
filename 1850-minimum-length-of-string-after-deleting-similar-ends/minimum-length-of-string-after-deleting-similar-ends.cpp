class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(i==j) return 1;
            if(s[i]==s[j])
            {
                while(i+1<s.size() && s[i]==s[i+1]) i++;
                while( j-1>=0 && s[j]==s[j-1]) j--;

                i++;
                j--;
            }
            else
            {
                return j-i+1;
            }
        }
        return 0;
    }
};