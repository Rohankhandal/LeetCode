class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ans(heights.begin(),heights.end());
        sort(ans.begin(),ans.end());
        int count=0;
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            if(heights[i]!=ans[i]) count++;
        }
        return count;
    }
};