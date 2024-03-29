class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int start=0,end=s.size()-1;
        while(start<end){
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else if(s[start]<s[end])
            {
                s[end]=s[start];
               
                start++;
                end--;
            }
            else
            {
                s[start]=s[end];
               
                start++;
                end--;
            }
        }
        return s;
    }
};