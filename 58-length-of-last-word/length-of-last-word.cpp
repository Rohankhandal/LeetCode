class Solution {
public:
    int lengthOfLastWord(string s) {
        int prevSpace=0;
        int n=s.size();
        // int ans=INT_MIN;
       int i=n-1;
      while(s[i]==' ')
      {
        i--;
      }
      string ans="";
      for(int j=0;j<=i;j++)
      {
        ans+=s[j];
      }

      for(i=0;i<ans.size();i++)
      {
        if(ans[i]==' ')
        {
            prevSpace=i+1;
        }
      }
    //   cout<<i<<" "<<prevSpace<<endl;
      int len=i-prevSpace;
    //   cout<<ans.size()<<" "<<s.size()<<endl;
        return len;
    }
};