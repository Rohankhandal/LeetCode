class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        if(colors[0]!=colors[n-1] && colors[n-1]!=colors[n-2]) ans++;
        if(colors[0]!=colors[n-1] && colors[0]!=colors[1]) ans++;
        for(int i=1;i<n-1;i++)
        {
             if(colors[i]!=colors[i-1] && colors[i]!=colors[i+1])
             {
                 ans++;
             }
        }
        return ans;
    }
};