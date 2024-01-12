class Solution {
public:
    int isvowel(string str)
    {
        int count=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            {
                count++;
            }
        }
        return count;
    }
   
    bool halvesAreAlike(string s) {
        int size=s.size();
        string a=s.substr(0,size/2);
        string b=s.substr(size/2,size/2);
        
        if(isvowel(a)==isvowel(b))
        {
            return true;
        }
        return false;
    }
};