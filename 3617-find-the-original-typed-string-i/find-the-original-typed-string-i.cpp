class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        unordered_map<int,int>mp;
        int i=0;
        int ans=1;
        while(i<n)
        {
            char ch=word[i];
            int cnt=0;
            while(i<n && word[i]==ch)
            {
                cnt++;
                i++;
            }
            ans+=max(0,cnt-1);
        }
        return ans;


        
    }
};