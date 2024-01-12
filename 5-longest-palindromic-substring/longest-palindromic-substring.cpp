class Solution {
public:


//Naive Approach   
//Better Approach using DP

    string isPalindrome(string s , int start , int end){

        while(start>=0 && end<s.size())
        {
            if(s[start] != s[end])
            {
                 break;
            }
            start--; end++;
        }
        return s.substr(start+1,end-start-1);
    }


    string longestPalindrome(string s) {
        string ans="";
        ans+=s[0];
        if(s.size()<=1)
        {
            return s;
        }
        for(int i=0 ; i<s.size()-1 ; i++)
        {
            string str1=isPalindrome(s,i,i);
            string str2=isPalindrome(s,i,i+1);
            if(str1.size()>ans.size())
            {
                ans=str1;
            }
            if(str2.size()>ans.size())
            {
                ans=str2;
            }
        }
        return ans;
    }
};