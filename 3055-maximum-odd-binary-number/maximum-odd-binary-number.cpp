class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans=string(s.size(),'0');
        int oneCount=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') oneCount++;
        }
        cout<<oneCount<<endl;
        //now rearrange string
        int l=0;
        int r=ans.size()-1;
        int right=1;
        //put one 1 in last
        ans[r]='1';
        oneCount--;
        //now put all 1's in start
        while(oneCount)
        {
            ans[l++]='1';
            oneCount--;
        }
        return ans;


    }
};