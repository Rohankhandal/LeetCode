class Solution {
public:
    bool isValidPalindromeAfterDelete(string s, int l,int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                return isValidPalindromeAfterDelete(s,l+1,r) || isValidPalindromeAfterDelete(s,l,r-1);
            }
        }
        return true;
    }
};