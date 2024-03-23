class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int n=s.size();
        int i=0;
        int sign=1;
        while(s[i]==' ')
        {
            i++;
        }
        if(i<n && s[i]=='-')
        {
            i++;
            sign=-1;
        } 
        else if(s[i]=='+')
        {
            i++;
            sign=1;
        }
        while(i<n && isdigit(s[i]))
        {
            
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]>'7'))
            {
                return sign==-1?INT_MIN:INT_MAX;
               
            }
            
            ans=ans*10+(s[i]-'0');
            i++;
        }
        return ans*sign;
    }
};