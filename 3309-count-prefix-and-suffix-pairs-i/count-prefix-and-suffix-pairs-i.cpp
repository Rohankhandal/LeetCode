class Solution {
public:
     bool isPrefixAndSuffix(string &a,string &b)
     {
        int n1=a.size();
        int n2=b.size();
        if(n2<n1) return false;

        for(int i=0;i<n1;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        for(int i=0,j=n2-n1;i<n1;i++,j++)
        {
            if(a[i]!=b[j]) return false;
        }

        return true;

     }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j) continue;

                if(isPrefixAndSuffix(words[i],words[j])) cnt++;
            }
        }
        return cnt;
    }
};